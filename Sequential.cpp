#include <iostream>

using namespace std;

const int defaultSize = 100;

class SeqList{
private:
    int *data;
    int maxSize;
    int last;
public:
    SeqList();
    SeqList(int sz);            //构造函数
    SeqList(SeqList &L);        //复制构造函数
    ~SeqList(){delete[] data;}   //析构函数
    int Size(){return maxSize;};        //列表容纳的个数
    int Length(){return last + 1;};      //列表目前的长度
    int Search(int &x)const;              //寻找数据x对应的项
    int Locate(const int &i)const;                //第i项对应的值
    bool getData(const int &i, int &x)const;      //返回第i项对应的数据x;
    bool setData(const int &i,const int &x);             //将第i项对应的数据设置成x
    bool Insert(const int &i, const int &x);            //在第i项之后插入值x
    bool Remove(const int &i);             //移除第i项，并返回第i项的值
    bool isEmpty();                   //列表为空？
    bool isFull();                    //列表满了？
    void Input(const int *array, const int array_size);                       //输入
    void Output();                      //输出
    void reSize(const int &newSize);
    SeqList operator = (SeqList  &L);    //重载函数，利用“ = ”整体赋值
};

SeqList :: SeqList(){
    maxSize = defaultSize;
    last = -1;
    data = new int[maxSize];
    if(data == nullptr){
        cout<<"error : can't new a spase for Seqlist"<<endl;
    }
}
SeqList :: SeqList (int sz){
    if(sz > 0){
        maxSize = sz;
        last = -1;
        data = new int[maxSize];
        if(data == nullptr)cout<<"error : can't new a spase for Seqlist"<<endl;
    }
};

void SeqList :: reSize(const int &newSize){
    int oldSize = maxSize;
    maxSize = newSize;
    int *newdata = new int[newSize];
    for(int i = 0; i < Length(); ++i){
        newdata[i] = data[i];
    }
    delete [] data;
    data = newdata;
} 

int SeqList :: Search(int &x)const{
    for(int i = 0; i < maxSize -1; ++i){
        if(x == data[i]){
            return (i + 1);
        }
    }
    return 0;    
}

int SeqList :: Locate(const int &i)const{
    if(i >= 0 && i < maxSize ){
        return data[i-1];
    }
    else{
        cout<<"i is invaliable"<<endl;
        return 0;
    } 
}

bool SeqList :: getData(const int &i, int &x)const{
    if(i > 0 && i <= maxSize){
        x = data[i-1];
        return true;
    }
    else{
        cout<<"input 'i' is invalid"<<endl;
        return false;
    }
}

bool SeqList :: setData(const int &i, const int &x){
    if(i >= 0 && i < maxSize){
        data[i -1] = x;
        return true;
    }
    else{
        return false;
    }
}

void SeqList :: Input(const int *array, const int array_size){
    int i = 0;
    cout<<"the input is : ";
    if(array_size <= maxSize){
        for(int i = 0; i < array_size; ++i){
            cout<<array[i]<<" ";
            data[i] = array[i];
            ++last;
        }
        cout<<endl;
    }
    else{
        cout<<"array beyonds the space"<<endl;
    }
}

void SeqList :: Output(){
    cout<<"the output is : ";
    for(int i = 0; i < last + 1; ++i){
        cout<<data[i]<<" ";
    }
    cout<<endl;
}

bool SeqList :: isEmpty(){
    if(last == -1) return true;
    else return false;   
}

bool SeqList :: isFull(){
    if(last == maxSize - 1){
        return true;
    }
    else{
        return false;
    }
}
bool SeqList :: Insert(const int &i, const int &x){
    if(Length() < maxSize){
        last = last + 1;
        if(i <= last){
            for(int j = 1; j < last-i+2; ++j){
              data[last-j+1] = data[last-j];
            }  
            data[i-1] = x;          
        }
        else{
            data[i-1] = x;
        }      
    return true;
    }
    else{
        cout<<"error : this list is full, cannot insert"<<endl;
        return false;
    }
}

bool SeqList :: Remove(const int &i){
    if(!isEmpty() && i < Length()){
        last = last - 1;
        for(int j = 0; j < last-i+2; ++j){
            data[i-1+j] = data[i+j];
        }       
        return true;
    }
    else{
        cout<<"error : this list is empty, cannot remove or i is not avaliable"<<endl;
        return false;
    }
}


SeqList :: SeqList(SeqList &L){
    maxSize = L.Size();
    last = L.Length() - 1;
    int value = 0;
    data = new int[maxSize];
    for(int i = 1; i <= L.Length(); ++i){
        L.getData(i, value);
        data[i-1] = value;
    }
}

int main(){
    SeqList seq(50);
    int array[] = {1, 2, 3, 4, 5, 6};
    int array_size = sizeof(array)/sizeof(int);
    seq.Input(array, array_size);
    seq.Output();
    return 0;
}
