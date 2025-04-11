const express = require('express');
const router = express.Router();
const Transaction = require('../models/Transaction'); // Assuming a Mongoose model

// Create a new transaction
router.post('/transactions', async (req, res) => {
    try {
        const { amount, description } = req.body;
        const newTransaction = new Transaction({ amount, description });
        await newTransaction.save();
        res.status(201).json(newTransaction);
    } catch (error) {
        res.status(500).json({ error: error.message });
    }
});

// Get all transactions
router.get('/transactions', async (req, res) => {
    try {
        const transactions = await Transaction.find();
        res.json(transactions);
    } catch (error) {
        res.status(500).json({ error: error.message });
    }
});

// Get a specific transaction
router.get('/transactions/:id', async (req, res) => {
    try {
        const transaction = await Transaction.findById(req.params.id);
        if (!transaction) {
            return res.status(404).json({ error: 'Transaction not found' });
        }
        res.json(transaction);
    } catch (error) {
        res.status(500).json({ error: error.message });
    }
});

// Update a transaction
router.put('/transactions/:id', async (req, res) => {
    try {
        const updatedTransaction = await Transaction.findByIdAndUpdate(req.params.id, req.body, { new: true });
        if (!updatedTransaction) {
            return res.status(404).json({ error: 'Transaction not found' });
        }
        res.json(updatedTransaction);
    } catch (error) {
        res.status(500).json({ error: error.message });
    }
});

// Delete a transaction
router.delete('/transactions/:id', async (req, res) => {
    try {
        const deletedTransaction = await Transaction.findByIdAndDelete(req.params.id);
        if (!deletedTransaction) {
            return res.status(404).json({ error: 'Transaction not found' });
        }
        res.json({ message: 'Transaction deleted successfully' });
    } catch (error) {
        res.status(500).json({ error: error.message });
    }
});

module.exports = router;