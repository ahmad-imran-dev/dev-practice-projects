const pipeline = [
    { $match: { date: { $gte: ISODate("2023-01-01"), $lte: ISODate("2023-12-31") } } } },
{ $group: { _id: "$productCategory", totalSales: { $sum: "$price" } } },
{ $sort: { totalSales: -1 } },
{ $limit: 10 }
  ];

module.exports = pipeline