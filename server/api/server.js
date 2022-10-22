'use strict'
const express = require('express')
const app = express()
require('./config/config')
require('./database/connect')

const Lights = require('./database/models/lights')

app.use(express.json())

app.post('/lights/:id', async (req, res) => {
    try {
        const light = await Lights.findOne({ id: req.params.id })
        if (!light) {
            throw {
                status: 404,
                message: 'Light not found'
            }
        }
        light.state = req.body.state
        try {
            await light.save()
            res.status(200).send(light)
        } catch (error) {
            throw {
                status: 500,
                message: 'Error saving light state'
            }
        }
    } catch (e) {
        res.status(400).send(e)
    }
})

app.get('/lights', async (req, res) => {
    try {
        const light = new Lights({
            activatedBySensor: ['sensor0']
        })
        await light.save()
        // const lights = await Lights.find({})
        res.status(200).send(light)
    } catch (e) {
        res.status(400).send(e)
    }
})

app.post('/sensor/:id', async (req, res) => {
    try {
        const lights = await Lights.find({})
        lights.forEach(async (light) => {
            if (light.activatedBySensor.includes(req.params.id)) {
                light.state = req.body.state
                try {
                    await light.save()
                } catch (error) {
                    throw {
                        status: 500,
                        message: 'Error saving light state'
                    }
                }
            }
        })
        res.status(200).send(lights)
    } catch (e) {
        res.status(400).send(e)
    }
})

app.use((err, _req, res, _next) => {
    res.status(err.status || 500).json({message: err.message || 'Internal Server Error'})
})

app.listen(process.env.PORT, () => {
    console.log(`Server listening on port ${process.env.PORT}`)
})
