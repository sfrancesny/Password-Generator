// Assignment Code
var generateBtn = document.querySelector("#generate");

// Write password to the #password input
function writePassword() {
  var password = generatePassword();
  var passwordText = document.querySelector("#password");

  passwordText.value = password;
}

// Function to generate a secure password
function generatePassword() {
  // Prompting for password criteria
  var length = prompt("Enter the length of the password (between 8 and 128 characters):");
  length = parseInt(length);

  // Validating the length of the password
  if (isNaN(length) || length < 8 || length > 128) {
    alert("Invalid length! Password must be between 8 and 128 characters.");
    return "";
  }

  var includeLowercase = confirm("Include lowercase characters?");
  var includeUppercase = confirm("Include uppercase characters?");
  var includeNumeric = confirm("Include numeric characters?");
  var includeSpecial = confirm("Include special characters?");

  // Validating that at least one character type is selected
  if (!includeLowercase && !includeUppercase && !includeNumeric && !includeSpecial) {
    alert("You must select at least one character type!");
    return "";
  }

  // Defining character pools based on selected criteria
  var lowercaseChars = "abcdefghijklmnopqrstuvwxyz";
  var uppercaseChars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  var numericChars = "0123456789";
  var specialChars = "!@#$%^&*()_+~`|}{[]:;?><,./-=";

  var allChars = "";
  var password = "";

  // Adding selected character types to the pool
  if (includeLowercase) {
    allChars += lowercaseChars;
  }

  if (includeUppercase) {
    allChars += uppercaseChars;
  }

  if (includeNumeric) {
    allChars += numericChars;
  }

  if (includeSpecial) {
    allChars += specialChars;
  }

  // Generating the password
  for (var i = 0; i < length; i++) {
    var randomIndex = Math.floor(Math.random() * allChars.length);
    password += allChars.charAt(randomIndex);
  }

  return password;
}

// Add event listener to generate button
generateBtn.addEventListener("click", writePassword);
