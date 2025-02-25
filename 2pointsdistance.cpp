#include <iostream>
#include <cmath>

using namespace std;

// Constant for Earth's radius in meters
const double R = 6371000.0;

// Function to convert degrees to radians
double toRadians(double degree) {
    return degree * M_PI / 180.0;
}

// Function to calculate the distance between two points in 3D space
// given their latitude, longitude, and altitude
double hitungJarak(double lat1, double lon1, double alt1, double lat2, double lon2, double alt2) {
    // Convert latitude and longitude from degrees to radians
    lat1 = toRadians(lat1);
    lon1 = toRadians(lon1);
    lat2 = toRadians(lat2);
    lon2 = toRadians(lon2);

    // Calculate the differences in latitude and longitude
    double dLat = lat2 - lat1;
    double dLon = lon2 - lon1;

    // Haversine formula to calculate the great-circle distance
    double a = sin(dLat / 2) * sin(dLat / 2) +
               cos(lat1) * cos(lat2) *
               sin(dLon / 2) * sin(dLon / 2);

    // Calculate the angular distance in radians
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    // Calculate the distance on the surface of the Earth
    double jarakPermukaan = R * c;

    // Calculate the difference in altitude
    double dAlt = alt2 - alt1;

    // Calculate the total distance using the Pythagorean theorem
    double jarakTotal = sqrt(jarakPermukaan * jarakPermukaan + dAlt * dAlt);

    // Return the total distance
    return jarakTotal;
}

int main() {
    // Variables to store latitude, longitude, and altitude for two points
    double lat1, lon1, alt1;
    double lat2, lon2, alt2;

    // Prompt user for input for the first point
    cout << "Masukkan latitude, longitude, dan altitude (meter) untuk titik pertama: ";
    cin >> lat1 >> lon1 >> alt1;

    // Prompt user for input for the second point
    cout << "Masukkan latitude, longitude, dan altitude (meter) untuk titik kedua: ";
    cin >> lat2 >> lon2 >> alt2;

    // Calculate the distance between the two points
    double jarak = hitungJarak(lat1, lon1, alt1, lat2, lon2, alt2);

    // Output the calculated distance
    cout << "Jarak antara dua titik (meter): " << jarak << " meter" << endl;

    return 0;
}
