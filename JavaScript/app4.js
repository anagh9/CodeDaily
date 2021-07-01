console.log(Boolean(0)); // False;
console.log(Boolean(undefined)); // false
console.log(Boolean("Anagh")); // True
console.log(Boolean({})); // true
console.log(Boolean("")); // false

("use strict");

///////////////////////////////////////
// Activating Strict Mode
let hasDriversLicense = false;
const passTest = true;
if (passTest) hasDriversLicense = true;
if (hasDriversLicense) console.log("I can drive :D");
const interface = "Audio";
const private = 534;
console.log(interface);
console.log(private);
