#include<iostream>

using namespace std;

int main()
{
    char Astr[50], Bstr[50];
    cin >> Astr;
    cin >> Bstr;

    char* A, * B;

    A = Astr;
    B = Bstr;

    int i = 0, j = 0;

    while (A[i] != '\0' || B[j] != '\0') {
        if (A[i] == '\0' && A[i - 1] == B[j]) {
            while (B[j] != '\0') {
                if (B[j] != A[i - 1]) {
                    cout << Astr << " and " << Bstr << ": Not Uniq" << endl;
                    return 0;
                }
                j++;
            }
            if (A[i - 1] == B[j - 1]) {
                cout << Astr << " and " << Bstr << ": Uniq" << endl;
                return 0;
            }
        }
        if (B[j] == '\0' && B[j - 1] == A[i]) {
            while (A[i] != '\0') {
                if (A[i] != B[j - 1]) {
                    cout << Astr << " and " << Bstr << ": Not Uniq" << endl;
                    return 0;
                }
                i++;
            }
            if (B[j - 1] == A[i - 1]) {
                cout << Astr << " and " << Bstr << ": Uniq" << endl;
                return 0;
            }
        }
        if (A[0] != B[0]) {
            cout << Astr << " and " << Bstr << ": Not Uniq" << endl;
            return 0;
        }
        if (A[i] == B[j]) { i++; j++; }
        if (A[i] != B[j]) {
            if (A[i] == A[i - 1]) {
                i++;
                while (A[i] != B[j]) {
                    if (A[i] != A[i - 1] && A[i] != B[j]) {
                        cout << Astr << " and " << Bstr << ": Not Uniq" << endl;
                        return 0;
                    }
                    if (A[i] == '\0')
                        break;
                    i++;
                }
                if (A[i] != '\0' && A[i - 1] != B[j - 1]) {
                    cout << Astr << " and " << Bstr << ": Not Uniq" << endl;
                    return 0;
                }
            }
            else if (B[j] == B[j - 1]) {
                j++;
                while (B[j] != A[i]) {
                    if (B[j] != B[j - 1] && B[j] != A[i]) {
                        cout << Astr << " and " << Bstr << ": Not Uniq" << endl;
                        return 0;
                    }
                    if (B[j] == '\0')
                        break;
                    j++;
                }
                if (B[j] != '\0' && B[j - 1] != A[i - 1]) {
                    cout << Astr << " and " << Bstr << ": Not Uniq" << endl;
                    return 0;
                }
            }
            else {
                cout << Astr << " and " << Bstr << ": Not Uniq" << endl;
                return 0;
            }
        }
    }
    cout << Astr << " and " << Bstr << ": Uniq" << endl;
}