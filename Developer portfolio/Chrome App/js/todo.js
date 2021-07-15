const toDoForm = document.getElementById("todo-form");
const toDoList = document.getElementById("todo-list");
const toDoInput = toDoForm.querySelector("input");

// ToDo list
let toDos = [];

function saveToDo(){
    // Save toDo array as text
    localStorage.setItem("todo", JSON.stringify(toDos));
}

function deleteToDo(event){
    // Remove element from array and screen
    // update local storage
    const target = event.target.parentElement;
    toDos = toDos.filter(item => item.id !== parseInt(target.id));
    target.remove();
    saveToDo();
}

function makeToDo(todo){
    // Create li, span, button tag
    // button, span inside li tag
    const li = document.createElement("li");
    li.id = todo.id;
    const span = document.createElement("span");
    const button = document.createElement("button");
    button.innerText = "X";
    span.innerText = todo.text;

    // Button to delete ToDo element
    button.addEventListener("click", deleteToDo);

    li.appendChild(span);
    li.appendChild(button);
    
    
    // li tag to html document todo list
    toDoList.appendChild(li);
}

function handleToDoSubmit(event){
    // Prevent browser's default behavior
    // No refresh
    event.preventDefault();
    
    // Empty the input if pressed Enter
    // make todo object and save into local storage
    const newToDo = toDoInput.value;
    toDoInput.value = "";

    const newTodoObj= { // object
        text: newToDo,
        id: Date.now(),
    };

    toDos.push(newTodoObj);
    makeToDo(newTodoObj);
    saveToDo();
}

toDoForm.addEventListener("submit", handleToDoSubmit);

// get list from local storage
const savedToDos = localStorage.getItem("todo");
if(savedToDos !== null){ // if todo exists
    // text to js object
    // make todo list for each element
    const parsedToDos = JSON.parse(savedToDos);
    toDos = parsedToDos; // update previous todos
    parsedToDos.forEach(makeToDo);

}