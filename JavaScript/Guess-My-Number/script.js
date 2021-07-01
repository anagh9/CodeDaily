"use strict";
// Math.trunc => return floor of the No.
// Math.trunc(3.44) // 3
// Math.trunc(5.44) // 5
// Math.random() // return a No between 0 and 1
// Math.random() * 20 + 1 // return a random no between 1 to 20
// console.log("Hello World");

let secretNumber = Math.trunc(Math.random() * 20) + 1;
// let secretNumber =  12;
let score = 5;
let highscore = 0;

const displayMessage = function (message) {
  document.querySelector(".message").textContent = message;
};

document.querySelector(".check").addEventListener("click", () => {
  const guess = Number(document.querySelector(".guess").value);
  console.log(guess, typeof guess);

  // When there is no input
  if (!guess) {
    // document.querySelector('.message').textContent = '⛔️ No number!';
    displayMessage(" No Number!");
  }

  // When Player wins
  else if (guess === secretNumber) {
    displayMessage("🎉 Correct Number!");
    document.querySelector(".number").textContent = ++highscore;
    document.querySelector("body").style.backgroundColor = "#60b347";
    document.querySelector(".number").style.width = "30rem";
  }

  // When guess Wrong
  else if (guess != secretNumber) {
    if (score > 1) {
      displayMessage(guess > secretNumber ? "📈 Too high!" : "📉 Too low!");
      score--;
      document.querySelector(".number").textContent = score;
    } else {
      displayMessage("💥 You lost the game!");
      document.querySelector(".number").textContent = 0;
    }
  }
});

document.querySelector(".again").addEventListener("click", () => {
  secretNumber = Math.trunc(Math.random() * 20) + 1;
  displayMessage("Start guessing ....");
  //   document.querySelector(".score").textContent = score;
  score = 5;
  document.querySelector(".number").textContent = "?";
  //   document.querySelector(".guess").value = "";

  document.querySelector("body").style.backgroundColor = "#222";
  document.querySelector(".number").style.width = "15rem";
});
