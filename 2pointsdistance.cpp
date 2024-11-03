#include <iostream>
#include <cmath>

using namespace std;

const double R = 6371000.0;

double toRadians(double degree) {
    return degree * M_PI / 180.0;
}

double hitungJarak(double lat1, double lon1, double alt1, double lat2, double lon2, double alt2) {
    lat1 = toRadians(lat1);
    lon1 = toRadians(lon1);
    lat2 = toRadians(lat2);
    lon2 = toRadians(lon2);

    double dLat = lat2 - lat1;
    double dLon = lon2 - lon1;

    double a = sin(dLat / 2) * sin(dLat / 2) +
               cos(lat1) * cos(lat2) *
               sin(dLon / 2) * sin(dLon / 2);

    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    double jarakPermukaan = R * c;

    double dAlt = alt2 - alt1;

    double jarakTotal = sqrt(jarakPermukaan * jarakPermukaan + dAlt * dAlt);

    return jarakTotal;
}

int main() {
    double lat1, lon1, alt1;
    double lat2, lon2, alt2;

    cout << "Masukkan latitude, longitude, dan altitude (meter) untuk titik pertama: ";
    cin >> lat1 >> lon1 >> alt1;

    cout << "Masukkan latitude, longitude, dan altitude (meter) untuk titik kedua: ";
    cin >> lat2 >> lon2 >> alt2;

    double jarak = hitungJarak(lat1, lon1, alt1, lat2, lon2, alt2);

    cout << "Jarak antara dua titik (meter): " << jarak << " meter" << endl;

    return 0;
}
