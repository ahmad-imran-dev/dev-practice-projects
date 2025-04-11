var express = require('express');
var router = express.Router();
var transactions = require("../models/transactiona_model");

router.get('/', async function (req, res, next) {
  const allTransactions = await transactions.aggregate([
    {
      $group: {
        _id: account_number,
        total: {
          $sum: debit, credit
        }
      }
    }
  ]);
  res.json({ allTransactions: allTransactions });
});

module.exports = router;
