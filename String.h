using namespace std;

class String {
private:
    char *str;
    char *temp;
    int n;

public:
    String(string a = "") {
        str = new char[a.length()];
        for (int i=0; i<a.length(); i++)
            str[i] = a[i];
        n = a.length();
    }

    static void help() {
        cout<<"String Class Help:"<<endl<<endl;
    }

    static void info() {
        cout<<"String Class Information:"<<endl<<endl;
        cout<<"    Created by Jameel Kaisar"<<endl;
        cout<<endl;
    }

    void insert(char a, int b = -1) {
        int i;
        if (b>=0)
            i = b;
        else
            i = n+b+1;
        if (!(i>=0 && i<=n)) {
            cout<<"Invalid index!"<<endl;
            return;
        }
        n++;
        temp = str;
        str = new char[n];
        for (int j=0; j<n; j++)
            if (j<i)
                str[j] = temp[j];
            else if (j>i)
                str[j] = temp[j-1];
            else
                str[j] = a;
        delete temp;
    }

    void insert(string a, int b = -1) {
        if (a.length()==0) {
            cout<<"Empty string!"<<endl;
            return;
        }
        int i;
        if (b>=0)
            i = b;
        else
            i = n+b+1;
        if (!(i>=0 && i<=n)) {
            cout<<"Invalid index!"<<endl;
            return;
        }
        n += a.length();
        temp = str;
        str = new char[n];
        for (int j=0; j<n; j++)
            if (j<i)
                str[j] = temp[j];
            else if (j>=i+a.length())
                str[j] = temp[j-a.length()];
            else
                str[j] = a[j-i];
        delete temp;
    }

    void append(char a) {
        insert(a, -1);
    }

    void append(string a) {
        insert(a, -1);
    }

    void write(char a, int b) {
        int i;
        if (b>=0)
            i = b;
        else
            i = n+b;
        if (!(i>=0 && i<n)) {
            cout<<"Invalid index!"<<endl;
            return;
        }
        str[i] = a;
    }

    void write(string a, int b) {
        if (a.length()==0) {
            cout<<"Empty string!"<<endl;
            return;
        }
        int i;
        if (b>=0)
            i = b;
        else
            i = n+b;
        if (!(i>=0 && i<n)) {
            cout<<"Invalid index!"<<endl;
            return;
        }
        if (i+a.length() > n) {
            cout<<"Out of range!"<<endl;
            return;
        }
        for (int j=0; j<a.length(); j++)
            str[i+j] = a[j];
    }

    void remove(char a, int b = 1) {
        // Negative Index?
        if (b<=0) {
            cout<<"Invalid index!"<<endl;
            return;
        }
        int i = b;
        for (int j=0; j<n; j++) {
            if (i>1 && str[j]==a) {
                i--;
            }
            else if (i==1 && str[j]==a && j+1!=n) {
                str[j] = str[j+1];
                i--;
            }
            else if (i==1 && str[j]==a) {
                i--;
            }
            else if (i==0 && j+1!=n) {
                str[j] = str[j+1];
            }
        }
        if (i==0)
            n--;
    }

    void removeall(char a) {
        int i = 0, tmp;
        for (int j=0; j+i<n; j++) {
            if (str[j+i] == a) {
                tmp = i;
                while(j+tmp<n && str[j+tmp]==a) {
                    i++;
                    tmp++;
                }
            }
            if (i>0 && j+i<n)
                str[j] = str[j+i];
        }
        n -= i;
    }

    void remove(string a, int b = 1) {
        if (a.length()==0) {
            cout<<"Empty string!"<<endl;
            return;
        }
        if (b<=0) {
            cout<<"Invalid index!"<<endl;
            return;
        }
        int i = b;
        int k;
        for (int j=0; j<n; j++) {
            for (k=0; k<a.length(); k++)
                if (str[j+k] != a[k])
                    break;
            if (k == a.length()) {
                if (i == 1) {
                    for (int l=j; l+a.length()<n; l++)
                        str[l] = str[l+a.length()];
                    n -= a.length();
                    j = n;
                    break;
                }
                i--;
                j += a.length()-1;
            }
        }
    }

    void removeall(string a) {
        // (fixed) Hello ababcdcdab, abcd ?
        if (a.length()==0) {
            cout<<"Empty string!"<<endl;
            return;
        }
        int j;
        for (int i=0; i<n; i++) {
            for (j=0; j<a.length() && i+j<n; j++)
                if (str[i+j] != a[j])
                    break;
            if (j == a.length()) {
                for (int k=i; k+a.length()<n; k++)
                    str[k] = str[k+a.length()];
                n -= a.length();
                i--;
            }
        }
    }

    void pop(int a) {
        int i;
        if (a>=0)
            i = a;
        else
            i = n+a;
        if (!(i>=0 && i<n)) {
            cout<<"Invalid index!"<<endl;
            return;
        }
        n--;
        for (int j=i; j<n; j++)
            str[j] = str[j+1];
    }

    void pop(int a, int b) {
        int i;
        if (a>=0)
            i = a;
        else
            i = n+a;
        int j;
        if (b>=0)
            j = b;
        else
            j = n+b;
        if (!(i>=0 && i<n && j>=0 && j<n && j>=i)) {
            cout<<"Invalid index!"<<endl;
            return;
        }
        n -= j-i+1;
        for (int k=i; k<n; k++)
            str[k] = str[k+j-i+1];
    }

    void replace(char a, char b, int c = 1) {
        if (c<=0) {
            cout<<"Invalid index!"<<endl;
            return;
        }
        int i = c;
        for (int j=0; j<n; j++) {
            if (i>1 && str[j]==a) {
                i--;
            }
            else if (i==1 && str[j]==a) {
                str[j] = b;
                i--;
            }
        }
    }

    void replaceall(char a, char b) {
        for (int i=0; i<n; i++)
            if (str[i] == a)
                str[i] = b;
    }

    void replace(string a, string b, int c = 1) {
        if (a.length()==0) {
            cout<<"Empty string!"<<endl;
            return;
        }
        if (c<=0) {
            cout<<"Invalid index!"<<endl;
            return;
        }
        int cnt = c;
        int dif = a.length()-b.length();
        if (dif >= 0) {
            int j;
            for (int i=0; i<n-a.length()+1; i++) {
                for (j=0; j<a.length(); j++)
                    if (str[i+j] != a[j])
                        break;
                if (j == a.length()) {
                    if (cnt == 1) {
                        for (int k=0; k<b.length(); k++)
                            str[i+k] = b[k];
                        if (dif > 0) {
                            for (int k=i+b.length(); k+dif<n; k++) {
                                str[k] = str[k+dif];
                            }
                            n -= dif;
                        }
                        break;
                    }
                    cnt--;
                    i += a.length()-1;
                }
            }
        }
        else {
            dif *= -1;
            int j;
            temp = str;
            str = new char[n+dif];
            for (int i=0; i<n; i++) {
                for (j=0; j<a.length() && i+j<n; j++)
                    if (temp[i+j] != a[j])
                        break;
                if (j == a.length()) {
                    if (cnt == 1) {
                        for (int k=0; k<b.length(); k++)
                            str[i+k] = b[k];
                        for (int k=i+b.length(); k<n+dif; k++)
                            str[k] = temp[k-dif];
                        break;
                    }
                    cnt--;
                }
                str[i] = temp[i];
            }
            n += dif;
            delete temp;
        }
    }

    void replaceall(string a, string b) {
        if (a.length()==0) {
            cout<<"Empty string!"<<endl;
            return;
        }
        int dif = a.length()-b.length();
        if (dif >= 0) {
            int j;
            for (int i=0; i<n-a.length()+1; i++) {
                for (j=0; j<a.length(); j++)
                    if (str[i+j] != a[j])
                        break;
                if (j == a.length()) {
                    for (int k=0; k<b.length(); k++)
                        str[i+k] = b[k];
                    if (dif > 0) {
                        for (int k=i+b.length(); k+dif<n; k++) {
                            str[k] = str[k+dif];
                        }
                        n -= dif;
                    }
                    i += b.length()-1;
                }
            }
        }
        else {
            dif *= -1;
            int cnt = count(a);
            int tmp = 0;
            int j;
            temp = str;
            str = new char[n+cnt*dif];
            for (int i=0; i<n; i++) {
                for (j=0; j<a.length() && i+j<n; j++)
                    if (temp[i+j] != a[j])
                        break;
                if (j == a.length()) {
                    for (int k=0; k<b.length(); k++)
                        str[i+k+tmp*dif] = b[k];
                    tmp++;
                    i += a.length()-1;
                    continue;
                }
                str[i+tmp*dif] = temp[i];
            }
            n += cnt*dif;
            delete temp;
        }
    }

    void censor(string a, char b = '*') {
        if (a.length()==0) {
            cout<<"Empty string!"<<endl;
            return;
        }
        int j;
        for (int i=0; i<n-a.length()+1; i++) {
            for (j=0; j<a.length(); j++)
                if (str[i+j] != a[j])
                    break;
            if (j == a.length()) {
                for (int k=0; k<a.length(); k++)
                    str[i+k] = b;
                i += a.length()-1;
            }
        }
    }

    void censor(int a, int b, char c = '*') {
        int i;
        if (a>=0)
            i = a;
        else
            i = n+a;
        int j;
        if (b>=0)
            j = b;
        else
            j = n+b;
        if (!(i>=0 && i<n && j>=0 && j<n && j>=i)) {
            cout<<"Invalid index!"<<endl;
            return;
        }
        for (int k=i; k<=j; k++)
            str[k] = c;
    }

    void reverse() {
        char tmp;
        for (int i=0; i<n/2; i++) {
            tmp = str[i];
            str[i] = str[n-i-1];
            str[n-i-1] = tmp;
        }
    }

    char get(int a) {
        int i;
        if (a>=0)
            i = a;
        else
            i = n+a;
        if (!(i>=0 && i<n)) {
            cout<<"Invalid index!"<<endl;
            return '?';
        }
        return str[i];
    }

    string get(int a, int b) {
        int i;
        if (a>=0)
            i = a;
        else
            i = n+a;
        int j;
        if (b>=0)
            j = b;
        else
            j = n+b;
        if (!(i>=0 && i<n && j>=0 && j<n)) {
            cout<<"Invalid index!"<<endl;
            return "?";
        }
        char *tmp = new char[((j>=i)?(j-i+2):(i-j+2))];
        if (j>=i) {
            for (int k=i, l=0; k<=j; k++, l++)
                tmp[l] = str[k];
            tmp[j-i+1] = '\0';
        }
        else {
            for (int k=i, l=0; k>=j; k--, l++)
                tmp[l] = str[k];
            tmp[i-j+1] = '\0';
        }
        return (string)tmp;
    }

    bool present(char a) {
        for (int i=0; i<n; i++)
            if (str[i] == a)
                return true;
        return false;
    }

    bool present(string a) {
        if (a.length()==0) {
            cout<<"Empty string!"<<endl;
            return false;
        }
        int j;
        for (int i=0; i<n-a.length()+1; i++) {
            for (j=0; j<a.length(); j++)
                if (str[i+j] != a[j])
                    break;
            if (j == a.length()) {
                return true;
            }
        }
        return false;
    }

    int count(char a) {
        int i = 0;
        for (int j=0; j<n; j++)
            if (str[j] == a)
                i++;
        return i;
    }

    int count(string a) {
        if (a.length()==0) {
            cout<<"Empty string!"<<endl;
            return -1;
        }
        int cnt = 0;
        int j;
        for (int i=0; i<n-a.length()+1; i++) {
            for (j=0; j<a.length(); j++)
                if (str[i+j] != a[j])
                    break;
            if (j == a.length()) {
                cnt++;
                i += a.length()-1;
            }
        }
        return cnt;
    }

    int length() {
        return n;
    }

    void print() {
        for (int i=0; i<n; i++)
            cout<<str[i];
    }

    void println() {
        for (int i=0; i<n; i++)
            cout<<str[i];
        cout<<endl;
    }

    void clear() {
        delete str;
        str = new char[0];
        n = 0;
    }
};
