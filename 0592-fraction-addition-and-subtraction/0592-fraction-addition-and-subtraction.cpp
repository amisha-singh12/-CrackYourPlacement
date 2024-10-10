class Solution {
public:
    string fractionAddition(string expression) {
        int num =0;
        int den = 1;

        int i = 0;
        int n = expression.size();
        while(i < n) {
            int currnum = 0;
            int currden = 0;

            bool isNeg = (expression[i] == '-');

            if(expression[i] == '+'  || expression[i] == '-'){
                i++;
            }

            // building the current numerator
            while(i < n && isdigit(expression[i])) {
                int val = expression[i] - '0';
                currnum = (currnum*10) + val;
                i++;
            }
            i++; // to skip this -> / 

              if (isNeg) {
                currnum = -currnum;  // Apply the negative sign to the entire numerator
            }

            // build the currdeno 
            while(i < n && isdigit(expression[i])) {
                int val = expression[i] - '0';
                currden = (currden*10) + val;
                i++;
            }
            num = num * currden + currnum * den;
            den = den * currden;
        }
         
            int GCD = abs(__gcd(num ,den)) ;
            num /= GCD;
            den /= GCD;

            return to_string(num) + "/" + to_string(den); 
    }
};