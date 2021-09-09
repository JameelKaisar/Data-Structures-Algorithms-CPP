using namespace std;

class Array {
private:
    int *array;
    int *temp;
    int n;

public:
    Array() {
        array = new int[0];
        n = 0;
    }

    static void help() {
        cout<<"Array Class Help:"<<endl<<endl;
    }

    static void info() {
        cout<<"Array Class Information:"<<endl<<endl;
        cout<<"    Created by Jameel Kaisar"<<endl;
        cout<<endl;
    }

    void insert(int a, int b = -1) {
        int index;
        if (b>=0)
            index = b;
        else
            index = n+b+1;
        if (!(index>=0 && index<=n)) {
            cout<<"Invalid index!"<<endl;
            return;
        }
        n++;
        temp = array;
        array = new int[n];
        for (int i=0; i<n; i++)
            if (index==i)
                array[i] = a;
            else if (index>i)
                array[i] = temp[i];
            else
                array[i] = temp[i-1];
        delete temp;
    }

    void append(int a) {
        insert(a, -1);
    }

    void set(int a, int b) {
        int i;
        if (b>=0)
            i = b;
        else
            i = n+b;
        if (!(i>=0 && i<n)) {
            cout<<"Invalid index!"<<endl;
            return;
        }
        array[i] = a;
    }

    void remove(int a, int b = 1) {
        // Negative Index?
        if (b<=0) {
            cout<<"Invalid index!"<<endl;
            return;
        }
        int i = b;
        for (int j=0; j<n; j++) {
            if (i>1 && array[j]==a) {
                i--;
            }
            else if (i==1 && array[j]==a && j+1!=n) {
                array[j] = array[j+1];
                i--;
            }
            else if (i==1 && array[j]==a) {
                i--;
            }
            else if (i==0 && j+1!=n) {
                array[j] = array[j+1];
            }
        }
        if (i==0)
            n--;
    }

    void removeall(int a) {
        int i = 0, tmp;
        for (int j=0; j+i<n; j++) {
            if (array[j+i] == a) {
                tmp = i;
                while(j+tmp<n && array[j+tmp]==a) {
                    i++;
                    tmp++;
                }
            }
            if (i>0 && j+i<n)
                array[j] = array[j+i];
        }
        n -= i;
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
            array[j] = array[j+1];
    }

    void reverse() {
        int tmp;
        for (int i=0; i<n/2; i++) {
            tmp = array[i];
            array[i] = array[n-i-1];
            array[n-i-1] = tmp;
        }
    }

    int get(int a) {
        int index;
        if (a>=0)
            index = a;
        else
            index = n+a;
        if (!(index>=0 && index<n)) {
            cout<<"Invalid index!"<<endl;
            return -1;
        }
        return array[index];
    }

    int index(int a, int b = 1) {
        // Negative Index?
        if (b<=0) {
            cout<<"Invalid index!"<<endl;
            return -1;
        }
        int i = b;
        for (int j=0; j<n; j++)
            if (i>1 && array[j]==a)
                i--;
            else if (array[j] == a)
                return j;
        return -1;
    }

    bool present(int a) {
        for (int i=0; i<n; i++)
            if (array[i] == a)
                return true;
        return false;
    }

    int count(int a) {
        int cnt = 0;
        for (int i=0; i<n; i++)
            if (array[i] == a)
                cnt++;
        return cnt;
    }

    float mean() {
        float tmp = 0;
        for (int i=0; i<n; i++)
            tmp += array[i];
        tmp /= n;
        return tmp;
    }

    int total() {
        return n;
    }

    void print() {
        if (n == 0) {
            cout<<"Array is empty!"<<endl;
            return;
        }
        for (int i=0; i<n; i++) {
            cout<<array[i];
            if (i != n-1)
                cout<<", ";
        }
        cout<<endl;
    }

    void clear() {
        delete array;
        array = new int[0];
        n = 0;
    }
};
