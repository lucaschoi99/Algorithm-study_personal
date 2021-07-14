const loginForm = document.querySelector("#login-form");
const loginInput = document.querySelector("#login-form input");
const greeting = document.querySelector("#greeting");
const HIDDEN = "hidden";
const USERNAME = "username";

function handleSubmit(event){
    // Prevent browser's default behavior
    // No refresh
    event.preventDefault(); 
    const username = loginInput.value;
    
    // Use Local storage to save username
    localStorage.setItem(USERNAME, username);

    // Hide form and show h1
    loginForm.classList.add(HIDDEN);
    Greetings(username);
}

function Greetings(username){
    greeting.innerText = `Hello! ${username}`;
    greeting.classList.remove(HIDDEN);
}

loginForm.addEventListener("submit", handleSubmit);

const savedUsername = localStorage.getItem(USERNAME);

if(savedUsername === null){
    // Show the form
    loginForm.classList.remove(HIDDEN);
    loginForm.addEventListener("submit", handleSubmit);
}
else{
    // Show the greetings when refreshed
    Greetings(savedUsername);
}