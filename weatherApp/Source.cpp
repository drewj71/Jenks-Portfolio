#include <iostream>
#include <curl/curl.h>
#include <nlohmann/json.hpp>

// Callback function to handle the received data
size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* output) {
    size_t total_size = size * nmemb;
    output->append((char*)contents, total_size);
    return total_size;
}

// Function to get coordinates based on city name
std::pair<double, double> getCoordinates(const std::string& city, const std::string& api_key) {
    std::string geocoding_api_endpoint = "https://api.openweathermap.org/data/2.5/weather?q=" +
        city +
        "&appid=" +
        api_key;

    // Initialize cURL for geocoding API
    CURL* geocoding_curl = curl_easy_init();
    std::pair<double, double> coordinates = { 0.0, 0.0 };

    if (geocoding_curl) {
        // Set up the callback function to handle the received data
        std::string geocoding_response_data;
        curl_easy_setopt(geocoding_curl, CURLOPT_URL, geocoding_api_endpoint.c_str());
        curl_easy_setopt(geocoding_curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(geocoding_curl, CURLOPT_WRITEDATA, &geocoding_response_data);

        // Perform the geocoding API call
        CURLcode geocoding_res = curl_easy_perform(geocoding_curl);

        // Check for errors
        if (geocoding_res == CURLE_OK) {
            // Parse the JSON response for geocoding
            nlohmann::json geocoding_response_json = nlohmann::json::parse(geocoding_response_data);

            // Check if the response contains valid coordinates
            if (geocoding_response_json.contains("coord") &&
                geocoding_response_json["coord"].contains("lat") &&
                geocoding_response_json["coord"].contains("lon")) {
                coordinates.first = geocoding_response_json["coord"]["lat"];
                coordinates.second = geocoding_response_json["coord"]["lon"];
            }
        }

        // Clean up geocoding cURL
        curl_easy_cleanup(geocoding_curl);
    }

    return coordinates;
}

// Function to convert temperature from Kelvin to Fahrenheit
double kelvinToFahrenheit(double kelvin) {
    return (kelvin - 273.15) * 9 / 5 + 32;
}

int main() {
    // Replace with your actual OpenWeatherMap API key
    std::string api_key = "a946817bbf33dd870345fe7d7c381f2c";

    // Get city name from user input
    std::cout << "Enter the city name: ";
    std::string city;
    std::getline(std::cin, city);

    // Get coordinates based on the entered city
    std::pair<double, double> coordinates = getCoordinates(city, api_key);

    if (coordinates.first != 0.0 && coordinates.second != 0.0) {
        std::cout << "Coordinates for " << city << ": " << coordinates.first << ", " << coordinates.second << std::endl;

        // Set the weather API endpoint with retrieved coordinates
        std::string weather_api_endpoint = "https://api.openweathermap.org/data/2.5/weather?lat=" +
            std::to_string(coordinates.first) +
            "&lon=" +
            std::to_string(coordinates.second) +
            "&appid=" +
            api_key;

        // Initialize cURL for weather API
        CURL* weather_curl = curl_easy_init();

        if (weather_curl) {
            // Set up the callback function to handle the received data
            std::string response_data;
            curl_easy_setopt(weather_curl, CURLOPT_URL, weather_api_endpoint.c_str());
            curl_easy_setopt(weather_curl, CURLOPT_WRITEFUNCTION, WriteCallback);
            curl_easy_setopt(weather_curl, CURLOPT_WRITEDATA, &response_data);

            // Perform the weather API call
            CURLcode weather_res = curl_easy_perform(weather_curl);

            // Check for errors
            if (weather_res == CURLE_OK) {
                // Parse the JSON response using nlohmann/json
                nlohmann::json response_json;

                try {
                    response_json = nlohmann::json::parse(response_data);

                    // Check if the "main" object exists in the JSON response
                    if (response_json.contains("main")) {
                        // Access specific data points
                        double temperature_kelvin = response_json["main"]["temp"];
                        double temperature_fahrenheit = kelvinToFahrenheit(temperature_kelvin);
                        double humidity = response_json["main"]["humidity"];
                        std::cout << "Temperature: " << temperature_fahrenheit << " °F\n";  // Temperature is in Kelvin
                        std::cout << "Humidity: " << humidity << "%\n";
                    }
                    else {
                        std::cout << "Error: Weather data not available.\n";
                    }
                }
                catch (const nlohmann::json::parse_error& e) {
                    std::cerr << "Error parsing JSON: " << e.what() << std::endl;
                }
            }
            else {
                fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(weather_res));
            }

            // Clean up weather API cURL
            curl_easy_cleanup(weather_curl);
        }
    }
    else {
        std::cout << "Error: Unable to retrieve coordinates for the entered city.\n";
    }

    return 0;
}
