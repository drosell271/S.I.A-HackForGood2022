'use strict'
const mongoose = require('mongoose')

const lightSchema = new mongoose.Schema({
    id: {
        type: String,
        required: true,
        unique: true,
        default: () => Math.random().toString(36).substring(2, 15) + Math.random().toString(36).substring(2, 15)
    },
    state: {
        type: Boolean,
        required: true,
        default: false
    },
    location: {
        type: String,
        required: true,
        default: 'Unknown'
    },
    activatedBySensor: [{
        type: String,
        required: false,
    }]
})

module.exports = mongoose.model('Light', lightSchema)
