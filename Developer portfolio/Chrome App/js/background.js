const images = ["0.jpeg","1.jpeg","2.jpeg", "3.jpeg","4.jpeg","5.jpeg"];

// Choose random images from the array
const chosenImg = images[Math.floor(Math.random() * images.length)];

// Create img tag
const bgImg = document.createElement("img");
bgImg.src = `img/${chosenImg}`;
bgImg.className = "bg";

// Image tag to html document
document.body.appendChild(bgImg);