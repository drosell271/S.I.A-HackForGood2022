'use strict'
const env = require('dotenv').config()
if (env.error) {
    throw env.error
}