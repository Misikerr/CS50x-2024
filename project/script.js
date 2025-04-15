// Create a new SpeechSynthesisUtterance object to handle speech settings
let speech = new SpeechSynthesisUtterance();

// Array to store the available voices
let voices = [];

// Select the <select> element from the DOM to list available voices
let voiceSelect = document.querySelector("select");

// When the list of available voices changes (triggered by the browser)
window.speechSynthesis.onvoiceschanged = () => {
    // Get the updated list of voices
    voices = window.speechSynthesis.getVoices();

    // Set the default voice to the first one in the list
    speech.voice = voices[0];

    // Populate the <select> dropdown with voice options
    voices.forEach((voice, i) => (
        voiceSelect.options[i] = new Option(voice.name, i) // Display voice name, set value as index
    ));
};

// When the user changes the selected voice in the dropdown
voiceSelect.addEventListener("change", () => {
    // Update the speech voice based on the selected option
    speech.voice = voices[voiceSelect.value];
});

// When the user clicks the button
document.querySelector("button").addEventListener("click", () => {
    // Get the text from the <textarea> and set it as the speech text
    speech.text = document.querySelector("textarea").value;

    // Use the Web Speech API to speak the text
    window.speechSynthesis.speak(speech);
});
