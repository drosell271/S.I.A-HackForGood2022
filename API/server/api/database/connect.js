'use strict'
// Connect to process.env.MONGODB_URI
const mongoose = require('mongoose')
mongoose.connect(process.env.MONGODB_URI, {}).then(() => {
    console.log('Connected to MongoDB')
}).catch((e) => {
    console.log(e)
})