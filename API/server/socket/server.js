'use strict'
const ws = require('ws')
const LightsClient = require('./classes/LightsClient')
require('./config/config')

const server = new ws.Server({
    port: process.env.PORT,
    host: "0.0.0.0",
}, () => {
    console.log(`WS server listening on port ${process.env.PORT}`)
})

server.on('connection', (socket) => {
    console.log('New connection')
    socket.on('message', async (data, isBinary) => {
        const message = isBinary ? data : data.toString()
        console.log(`Message received: ${message}`)
        switch (message) {
            case 'ping':
                socket.send('pong')
                return
            default:
                break
        }
        let json
        try {
            json = JSON.parse(message)
        } catch (e) {
            return console.log(e)
        }
        console.log({ json })
        try {
            let lights = json.map(async (light) => {
                const lightClient = new LightsClient(light)
                return lightClient.execute()
            })
            lights = (await Promise.allSettled(lights))
                .filter((light) => light.status === 'fulfilled')
                .map((light) => light.value)
            console.log({ lights })
            socket.send(JSON.stringify(lights))
        } catch (e) {
            console.log(e)
        }
    })
    socket.send('Hello from server')
})
