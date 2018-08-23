#include <iostream>
#include <exception>
#include <string>
#include <stdexcept>
#include <vector>
#include <cmath>
#include "exceptional_server.h"

using namespace std;

// START HACKERRANK BOILERPLATE
class Server {
private:
    static int load;
public:
    static int compute (long long A, long long B) {
        load += 1;
        if (A < 0) {
            throw std::invalid_argument("A is negative");
        }
        vector<int> v(A, 0);
        int real = -1, cmplx = sqrt(-1);
        if (B == 0) throw 0;
        real = (A / B)*real;
        int ans = v.at(B);
        return real + A - B * ans;
    }
    static int getLoad() {
        return load;
    }
};
int Server::load = 0;

int hackerrank::exceptional_server ()
{
    int T; cin >> T;
    while (T--) {
        long long A, B;
        cin >> A >> B;
 // END HACKERRANK BOILERPLATE
        try {
            int result = Server::compute(A, B);
            cout << result << endl;
        }
        catch (invalid_argument& e) {
            cout << "Exception: " << e.what() << endl;
        }
        catch (bad_alloc& e) {
            cout << "Not enough memory" << endl;
        }
        catch (exception& e) {
            cout << "Exception: " << e.what() << endl;
        }
        catch (int e) {
            cout << "Other Exception" << endl;
        }
 // START HACKERRANK BOILERPLATE
    }
    cout << Server::getLoad() << endl;
    return 0;
}
// END HACKERRANK BOILERPLATE
