const { Kafka } = require("kafkajs");

exports.kafka = new Kafka({
  clientId: "new-kafka",
  brokers: ["192.168.10.5:9092"],
});