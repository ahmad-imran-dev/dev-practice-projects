var express = require('express');
var router = express.Router();
const redis = require("../utils/redis-client");
const axios = require("axios").default;


router.get('/', async function (req, res, next) {
  // const data = await axios.get('https://jsonplaceholder.typicode.com/posts');
  // const result = await data.json();
  const data = await redis.get("transaction:credit");
  console.log(data);

  if (!data) {
    redis.set("transaction:credit", 345);
    res.json({ result: 345 });
    console.log(true);

  } else {
    res.json({ result: data });
    console.log(false);

  }
});

module.exports = router;
