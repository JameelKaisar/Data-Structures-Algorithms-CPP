using namespace std;

class Matrix {
private:
    int **matrix;
    int **temp;
    int m, n;

    int det(int** a, int b) {
        if (b==1)
            return a[0][0];
        int d = 0;
        int **tmp;
        for (int i=0; i<b; i++) {
            tmp = new int*[b-1];
            for (int j=0; j<b-1; j++)
                tmp[j] = new int[b-1];
            for (int j=0; j<b-1; j++)
                for (int k=0; k<b-1; k++)
                    if (k<i)
                        tmp[j][k] = a[j+1][k];
                    else
                        tmp[j][k] = a[j+1][k+1];
            d += ((i%2==0)?1:-1)*(a[0][i] * det(tmp, b-1));
            for (int j=0; j<b-1; j++)
                delete [] tmp[j];
            delete [] tmp;
        }
        return d;
    }

public:
    Matrix(int a = 0, int b = 0) {
        if (a<0 || b<0)
            throw invalid_argument("Invalid Arguments!");
        matrix = new int*[a];
        for (int i=0; i<a; i++)
            matrix[i] = new int[b];
        m = a;
        n = b;
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                matrix[i][j] = 0;
            }
        }
    }

    static void help() {
        cout<<"Matrix Class Help:"<<endl<<endl;
    }

    static void info() {
        cout<<"Matrix Class Information:"<<endl<<endl;
        cout<<"    Created by Jameel Kaisar"<<endl;
        cout<<endl;
    }

    void resize(int a, int b) {
        if (a<0 || b<0) {
            cout<<"Invalid Arguments!"<<endl;
            return;
        }
        if (a>m || b>n) {
            temp = matrix;
            matrix = new int*[a];
            for (int i=0; i<a; i++)
                matrix[i] = new int[b];
            for (int i=0; i<a; i++) {
                for (int j=0; j<b; j++) {
                    if (i<m && j<n)
                        matrix[i][j] = temp[i][j];
                    else
                        matrix[i][j] = 0;
                }
            }
            for (int i=0; i<m; i++)
                delete [] temp[i];
            delete [] temp;
        }
        else {
            for (int i=a; i<m; i++)
                delete [] matrix[i];
        }
        m = a;
        n = b;
    }

    void set(int a, int b, int c) {
        int i;
        if (b>=0)
            i = b;
        else
            i = m+b;
        int j;
        if (c>=0)
            j = c;
        else
            j = n+c;
        if (!(i>=0 && i<m && j>=0 && j<n)) {
            cout<<"Invalid index!"<<endl;
            return;
        }
        matrix[i][j] = a;
    }

    void zerorow(int a) {
        int i;
        if (a>=0)
            i = a;
        else
            i = m+a;
        if (!(i>=0 && i<m)) {
            cout<<"Invalid index!"<<endl;
            return;
        }
        for (int j=0; j<n; j++)
            matrix[i][j] = 0;
    }

    void zerocolumn(int a) {
        int i;
        if (a>=0)
            i = a;
        else
            i = n+a;
        if (!(i>=0 && i<n)) {
            cout<<"Invalid index!"<<endl;
            return;
        }
        for (int j=0; j<m; j++)
            matrix[j][i] = 0;
    }

    void removerow(int a) {
        int i;
        if (a>=0)
            i = a;
        else
            i = m+a;
        if (!(i>=0 && i<m)) {
            cout<<"Invalid index!"<<endl;
            return;
        }
        for (int j=i; j<m-1; j++)
            for (int k=0; k<n; k++)
                matrix[j][k] = matrix[j+1][k];
        m--;
        delete [] matrix[m];
    }

    void removecolumn(int a) {
        int i;
        if (a>=0)
            i = a;
        else
            i = n+a;
        if (!(i>=0 && i<n)) {
            cout<<"Invalid index!"<<endl;
            return;
        }
        for (int j=0; j<m; j++)
            for (int k=i; k<n-1; k++)
                matrix[j][k] = matrix[j][k+1];
        n--;
    }

    void insertrow(int a) {
        int i;
        if (a>=0)
            i = a;
        else
            i = m+a+1;
        if (!(i>=0 && i<=m)) {
            cout<<"Invalid index!"<<endl;
            return;
        }
        temp = matrix;
        matrix = new int*[m+1];
        for (int j=0; j<m+1; j++)
            matrix[j] = new int[n];
        for (int j=0; j<m+1; j++)
            for (int k=0; k<n; k++)
                if (j<i) {
                    matrix[j][k] = temp[j][k];
                }
                else if (j>i) {
                    matrix[j][k] = temp[j-1][k];
                }
                else {
                    matrix[j][k] = 0;
                }
        for (int j=0; j<m; j++)
            delete [] temp[j];
        delete [] temp;
        m++;
    }

    void appendrow() {
        insertrow(-1);
    }

    void insertcolumn(int a) {
        int i;
        if (a>=0)
            i = a;
        else
            i = n+a+1;
        if (!(i>=0 && i<=n)) {
            cout<<"Invalid index!"<<endl;
            return;
        }
        temp = matrix;
        matrix = new int*[m];
        for (int j=0; j<m; j++)
            matrix[j] = new int[n+1];
        for (int j=0; j<m; j++)
            for (int k=0; k<n+1; k++)
                if (k<i) {
                    matrix[j][k] = temp[j][k];
                }
                else if (k>i) {
                    matrix[j][k] = temp[j][k-1];
                }
                else {
                    matrix[j][k] = 0;
                }
        for (int j=0; j<m; j++)
            delete [] temp[j];
        delete [] temp;
        n++;
    }

    void appendcolumn() {
        insertcolumn(-1);
    }

    int get(int a, int b) {
        int i;
        if (a>=0)
            i = a;
        else
            i = m+a;
        int j;
        if (b>=0)
            j = b;
        else
            j = n+b;
        if (!(i>=0 && i<m && j>=0 && j<n)) {
            cout<<"Invalid index!"<<endl;
            return -1;
        }
        return matrix[i][j];
    }

    int count(int a) {
        int cnt = 0;
        for (int i=0; i<m; i++)
            for (int j=0; j<n; j++)
                if (matrix[i][j] == a)
                    cnt++;
        return cnt;
    }

    int countinrow(int a, int b) {
        int i;
        if (b>=0)
            i = b;
        else
            i = m+b;
        if (!(i>=0 && i<m)) {
            cout<<"Invalid index!"<<endl;
            return -1;
        }
        int cnt = 0;
        for (int j=0; j<n; j++)
            if (matrix[i][j] == a)
                cnt++;
        return cnt;
    }

    int countincolumn(int a, int b) {
        int i;
        if (b>=0)
            i = b;
        else
            i = n+b;
        if (!(i>=0 && i<n)) {
            cout<<"Invalid index!"<<endl;
            return -1;
        }
        int cnt = 0;
        for (int j=0; j<m; j++)
            if (matrix[j][i] == a)
                cnt++;
        return cnt;
    }

    int rows() {
        return m;
    }

    int columns() {
        return n;
    }

    void print() {
        if (m==0 || n==0) {
            cout<<"Matrix is empty!"<<endl;
            return;
        }
        for (int i=0; i<m; i++) {
            if (n>0)
                cout<<matrix[i][0];
            for (int j=1; j<n; j++) {
                    cout<<", "<<matrix[i][j];
            }
            cout<<endl;
        }
        cout<<endl;
    }

    void printrow(int a) {
        int i;
        if (a>=0)
            i = a;
        else
            i = m+a;
        if (!(i>=0 && i<m)) {
            cout<<"Invalid index!"<<endl;
            return;
        }
        if (n>0)
            cout<<matrix[i][0];
        for (int j=1; j<n; j++)
            cout<<", "<<matrix[i][j];
        cout<<endl;
    }

    void printcolumn(int a) {
        int i;
        if (a>=0)
            i = a;
        else
            i = n+a;
        if (!(i>=0 && i<n)) {
            cout<<"Invalid index!"<<endl;
            return;
        }
        if (m>0)
            cout<<matrix[0][i];
        for (int j=1; j<m; j++)
            cout<<", "<<matrix[j][i];
        cout<<endl;
    }

    void transpose() {
        temp = matrix;
        matrix = new int*[n];
        for (int i=0; i<n; i++)
            matrix[i] = new int[m];
        for (int i=0; i<n; i++)
            for (int j=0; j<m; j++)
                matrix[i][j] = temp[j][i];
        for (int i=0; i<m; i++)
            delete [] temp[i];
        delete [] temp;
        m = m+n;
        n = m-n;
        m = m-n;
    }

    int determinant() {
        if (m==0 || n==0 || m!=n) {
            cout<<"Determinant cannot be found!"<<endl;
            return -1;
        }
        return det(matrix, m);
    }

    void clear() {
        for (int i=0; i<m; i++)
            delete [] matrix[i];
        delete [] matrix;
        matrix = new int*[0];
        m = 0;
        n = 0;
    }
};
