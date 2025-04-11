const mongoose = require("mongoose");

const transactionSchema = new mongoose.Schema({
    email: String,
    account_number: Number,
    debit: Number,
    credit: Number,
    address: String
});

module.exports = mongoose.model('transactions', transactionSchema);