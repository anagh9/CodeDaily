const EventEmitter = require("events");
const http = require("http");
const fs = require("fs");
const { readFile } = require("fs/promises");

class Sales extends EventEmitter {
  constructor() {
    super();
  }
}

const myEmitter = new Sales();

myEmitter.on("newSale", () => {
  console.log("There was a new sale");
});
myEmitter.on("newSale", () => {
  console.log("Customer name : Anagh");
});

myEmitter.on("newSale", (stock) => {
  console.log(`There are now ${stock} items left in the stock`);
});

myEmitter.emit("newSale", 9);

const server = http.createServer();
server.on("request", (req, res) => {
  console.log("Request received!");
  console.log(req.url);
  res.end("Request received");
});

server.on("request", (req, res) => {
  const readable = fs.createReadStream("Implement.txt");
  readable.pipe(res);
});

server.listen(8000, "127.0.0.1", () => {
  console.log("Waiting for requests...");
});
