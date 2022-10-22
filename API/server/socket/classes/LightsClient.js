'use strict'
const fetch = (...args) => import('node-fetch').then(({default: fetch}) => fetch(...args));

class LightsClient {
    constructor({state, id}) {
        this.state = this.getBooleanState(state)
        this.id = id
    }

    getBooleanState(state) {
        const possibleStates = {
            'on': true,
            'off': false,
            'true': true,
            'false': false,
            '1': true,
            '0': false,
            'HIGH': true,
            'LOW': false,
        }
        return possibleStates[state.toString()]
    }

    async execute() {
        console.log(`Executing ${this.state} on ${this.id}`)
        const response = await fetch(`${process.env.API_URL}/lights/${this.id}`, {
            method: 'POST',
            headers: {
                'Content-Type': 'application/json',
            },
            body: JSON.stringify({
                state: this.state,
                id: this.id,
            }),
        })
        if (!response.ok)
            throw {
                status: response.status,
                statusText: response.statusText,
            }
        return await response.json()
    }
}

module.exports = LightsClient
