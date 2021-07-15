const clock = document.querySelector("#clock");

function getClock(){
    // Create date object
    const date = new Date();

    // Hours, minutes, seconds to string
    // text formatting by using padStart function
    const hours = String(date.getHours()).padStart(2,"0");
    const minutes = String(date.getMinutes()).padStart(2,"0");
    const seconds = String(date.getSeconds()).padStart(2,"0");
    
    // clock info
    clock.innerText=`${hours}:${minutes}:${seconds}`;
}

// Show clock every 1 second
getClock();
setInterval(getClock, 1000);