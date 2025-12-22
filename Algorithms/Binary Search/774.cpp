// Minimize max Distance to Gas Station

#include<bits/stdc++.h>

using namespace std;

bool canAchieve(const vector<int>& stations, int k, double maxDist) {
    int requiredStations = 0;

    for (int i = 1; i < stations.size(); i++) {
        double gap = stations[i] - stations[i - 1];
        requiredStations += (int)(gap / maxDist);
        if (requiredStations > k) return false;
    }
    return true;
}

double minmaxGasDist(vector<int>& stations, int k) {
    double left = 0.0;
    double right = stations.back() - stations.front();

    while (right - left > 1e-6) {
        double mid = (left + right) / 2.0;
        if (canAchieve(stations, k, mid))
            right = mid;
        else
            left = mid;
    }
    return right;
}