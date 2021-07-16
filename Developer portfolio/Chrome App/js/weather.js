const API_KEY = "aef18e28cb3eea7999377df721c944c1";

function geoSuccess(position){
    // Get url using api key
    const lat = position.coords.latitude;
    const long = position.coords.longitude;
    const url = `https://api.openweathermap.org/data/2.5/weather?lat=${lat}&lon=${long}&appid=${API_KEY}&units=metric`
    fetch(url)
        .then((response) => response.json())
        .then((data) =>{
            const city = document.querySelector("#weather span:first-child");
            const weather = document.querySelector("#weather span:last-child");
            
            city.innerText= `🧭${data.name} `;
            weather.innerText = `🌡${data.weather[0].main} ${data.main.temp}°C`;
            
        });
    

}

function geoError(){
    alert("Failed to find your location...");
}

// geolocation function
navigator.geolocation.getCurrentPosition(geoSuccess, geoError);