#include <iostream>
#include <string>
using namespace std;
class CoreTradingEngine {
protected:
    double orderVolume;
    string assetSymbol;
public:
    CoreTradingEngine(double vol, string sym) {
        orderVolume = vol;
        assetSymbol = sym;
    }
    void executeOrder(double price) {
        cout << "Core engine: executing " << orderVolume << " of " << assetSymbol
             << " at price " << price << endl;
    }
};
// private inheritance makes executeOrder private inside EncryptedRiskEngine
class EncryptedRiskEngine : private CoreTradingEngine {
protected:
    bool validateRiskThreshold(double price) {
        if (price > 0 && price < 10000) {
            return true;
        }
        return false;
    }
public:
    EncryptedRiskEngine(double vol, string sym) : CoreTradingEngine(vol, sym) {}
    void processSecureTrade(double price, double volatilityScore) {
        if (validateRiskThreshold(price) && volatilityScore < 0.7) {
            cout << "Risk check passed" << endl;
            executeOrder(price);   // allowed, we are inside the class
        } else {
            cout << "Trade rejected by risk engine" << endl;
        }
    }
};
class HighFrequencyBot : public EncryptedRiskEngine {
public:
    HighFrequencyBot(double vol, string sym) : EncryptedRiskEngine(vol, sym) {}
    void runBot(double price) {
        // cannot call executeOrder here, it is private in EncryptedRiskEngine
        processSecureTrade(price, 0.3);
    }
};
int main() {
    HighFrequencyBot bot(500, "AAPL");
    cout << "Trade 1 (safe):" << endl;
    bot.processSecureTrade(150, 0.3);
    cout << "\nTrade 2 (too volatile):" << endl;
    bot.processSecureTrade(150, 0.9);
    cout << "\nTrade 3 (price too high):" << endl;
    bot.processSecureTrade(50000, 0.1);
    cout << "\nBot running:" << endl;
    bot.runBot(200);
    return 0;
}
