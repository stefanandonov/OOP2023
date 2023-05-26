#include<iostream>
#include<cstring>
#include<stdlib.h>

using namespace std;

class WrongLabelsFormatException {
public:
    void message() {
        cout << "Labels must have the same length";
    }
};

class Evaluator {
protected:
    char actual[100];
    char predicted[100];
public:
    Evaluator(char *actual, char *predicted) {
        if (strlen(actual)!=strlen(predicted)){
            throw WrongLabelsFormatException();
        }
        strcpy(this->actual, actual);
        strcpy(this->predicted, predicted);
    }

    virtual void print () = 0;
    virtual double evaluate() = 0;

    bool operator >= (Evaluator & e) {
        return this->evaluate() >= e.evaluate();
    }
};

class AccuracyEvaluator : public Evaluator {
public:
    AccuracyEvaluator(char *actual, char *predicted) : Evaluator(actual, predicted) {}

    void print() override {
        cout << "Number of data points: " << strlen(actual) <<  " Prediction Accuracy: " << evaluate() << endl;
    }

    double evaluate() override {
        int matches = 0;
        for (int i=0;i<strlen(actual);i++){
            if (actual[i]==predicted[i]){
                matches++;
            }
        }
        return (double) matches / strlen(actual);
    }
};

class SensitivityEvaluator : public Evaluator {
public:
    SensitivityEvaluator(char *actual, char *predicted) : Evaluator(actual, predicted) {}

    void print() override {
        cout << "Number of data points: " << strlen(actual) <<  " Prediction Sensitivity: " << evaluate() << endl;
    }

    double evaluate() override {
        int matches = 0, actualPositive = 0;
        for (int i=0;i<strlen(actual);i++){
            if (actual[i]=='+'){
                actualPositive++;
                if (actual[i]==predicted[i]){
                    matches++;
                }
            }

        }
        return (double) matches / actualPositive;

    }
};

Evaluator *highestScore(Evaluator **evaluators, int n);

Evaluator *bestSensitivyEvaluator(Evaluator **evaluators, int n) {
    Evaluator * max = nullptr;
    for (int i=0;i<n;i++){
        SensitivityEvaluator *res = dynamic_cast<SensitivityEvaluator *>(evaluators[i]);
        if (res){
            if (max== nullptr) {
                max = evaluators[i];
            } else {
                if ((*evaluators[i]) >= (*max)){
                    max = evaluators[i];
                }
            }
        }

    }
    return max;
}
int main() {
    int testCase;
    char trueLabels[100];
    char predictedLabels[100];
    cin >> testCase;
    if (testCase == 1) {
        cout << "TESTING CREATION OF ACCURACY EVALUATOR. EXCEPTION CAN HAPPEN HERE!" << endl;
        cin >> trueLabels >> predictedLabels;

        try{
            Evaluator *evaluator = new AccuracyEvaluator(trueLabels, predictedLabels);
            cout << evaluator->evaluate() << endl;
            evaluator->print();
        } catch (WrongLabelsFormatException & e) {
            e.message();
        }
        
    } else if (testCase == 2) {
        cout << "TESTING CREATION OF ACCURACY EVALUATOR. EXCEPTION CAN HAPPEN HERE!" << endl;
        cin >> trueLabels >> predictedLabels;

        try{
            Evaluator *evaluator = new SensitivityEvaluator(trueLabels, predictedLabels);
            cout << evaluator->evaluate() << endl;
            evaluator->print();
        }catch (WrongLabelsFormatException & e) {
            e.message();
        }


    } else if (testCase == 3) {
        cout << "TESTING CREATION OF BOTH EVALUATORS. EXCEPTION CAN HAPPEN HERE!" << endl;
        cin >> trueLabels >> predictedLabels;

        try{
            Evaluator *accuracy = new AccuracyEvaluator(trueLabels, predictedLabels);
            Evaluator *sensitivity = new SensitivityEvaluator(trueLabels, predictedLabels);
            accuracy->print();
            sensitivity->print();
        } catch (WrongLabelsFormatException & e) {
            e.message();
        }

    } else if (testCase == 4) {
        cout << "TESTING OPERATOR >=" << endl;
        cin >> trueLabels >> predictedLabels;
        Evaluator *accuracy = new AccuracyEvaluator(trueLabels, predictedLabels);
        Evaluator *sensitivity = new SensitivityEvaluator(trueLabels, predictedLabels);
        cin >> trueLabels >> predictedLabels;
        Evaluator *accuracy1 = new AccuracyEvaluator(trueLabels, predictedLabels);
        Evaluator *sensitivity1 = new SensitivityEvaluator(trueLabels, predictedLabels);

        accuracy->print();
        cout << (((*accuracy) >= (*sensitivity)) ? ">=" : "<") << endl;
        sensitivity->print();
        cout << endl;

        sensitivity->print();
        cout << (((*sensitivity) >= (*accuracy)) ? ">=" : "<") << endl;
        accuracy->print();
        cout << endl;

        accuracy->print();
        cout << (((*accuracy) >= (*accuracy1)) ? ">=" : "<") << endl;
        accuracy1->print();
        cout << endl;

        sensitivity->print();
        cout << (((*sensitivity) >= (*sensitivity1)) ? ">=" : "<") << endl;
        sensitivity1->print();
        cout << endl;
    } else {
        cout << "INTEGRATION TEST AND TESTING GLOBAL FUNCTION. EXCEPTION CAN HAPPEN HERE!" << endl;
        int n;
        cin >> n;
        Evaluator **evaluators = new Evaluator *[n];
        for (int i = 0; i < n; i++) {
            int type;
            cin >> type;
            cin >> trueLabels >> predictedLabels;
            try {
                if (type == 1) { //accuracy
                    evaluators[i] = new AccuracyEvaluator(trueLabels, predictedLabels);
                } else { //sensitivity
                    evaluators[i] = new SensitivityEvaluator(trueLabels, predictedLabels);
                }
            } catch (WrongLabelsFormatException & e) {
                e.message();
                --n;
                --i;
            }


        }

        cout << "PRINT ALL EVALUATORS FIRST!" << endl;
        for (int i = 0; i < n; i++) {
            evaluators[i]->print();
        }

        cout << "RESULT FROM HIGHEST SCORE METHOD" << endl;
        highestScore(evaluators, n)->print();
    }

}

Evaluator *highestScore(Evaluator **evaluators, int n) {
    Evaluator * max = evaluators[0];
    for (int i=1;i<n;i++){
        if ((*evaluators[i]) >= (*max)){
            max = evaluators[i];
        }
    }
    return max;
}
