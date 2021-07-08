

//#include "head.h"
#include <iostream>
#include <iterator>
#include <list>
#include <fstream>
#include <cstring>
#include <string.h>
#include <vector>
#include <ctime>
#include <iomanip>

using namespace std;

class Books{    //图书类
private:
    static int allBookNum;//这本书的所有数量
    int bookId;//   编号，自动生成（allBookName+1）
    string bookName;    //书名
    string authorName;  //作者名
    int categoryNum;    //图书分类号
    string press;   //出版社or出版单位
    string printTime;   //出版时间
    double price;   //书的价格
    bool statue;
public:
    Books() {
    }

    Books( string bookName,  string authorName, int categoryNum,  string press,
           string printTime, double price, bool statue) {
        this->bookName = bookName;
        this->authorName = authorName;
        this->categoryNum =  categoryNum;
        this->press = press;
        this->printTime = printTime;
        this->price = price;
        this->statue = statue;

        bookId=allBookNum++;
        statue = true;
    }

    const int  getBookId() const {
        return bookId;
    }

    void setBookId(int bookId) {
        Books::bookId = bookId;
    }

    const string &getBookName() const {
        return bookName;
    }

    void setBookName(const string &bookName) {
        Books::bookName = bookName;
    }

    const string &getAuthorName() const {
        return authorName;
    }

    void setAuthorName(const string &authorName) {
        Books::authorName = authorName;
    }

    int getCategoryNum() const {
        return categoryNum;
    }

    void setCategoryNum(int categoryNum) {
        Books::categoryNum = categoryNum;
    }

    const string &getPress() const {
        return press;
    }

    void setPress(const string &press) {
        Books::press = press;
    }

    const string &getPrintTime() const {
        return printTime;
    }

    void setPrintTime(const string &printTime) {
        Books::printTime = printTime;
    }

    double getPrice() const {
        return price;
    }

    void setPrice(double price) {
        Books::price = price;
    }

    bool isStatue() const {
        return statue;
    }

    void setStatue(bool statue) {
        Books::statue = statue;
    }
    //存在状态（在true，或者不在false）
public:
    friend ostream & operator<<(ostream& s,Books & books){  //重载运算符
        s<<books.bookId<<","<<books.bookName<<","<<books.authorName<<","
         <<books.categoryNum<<","<<books.press<<","<<books.printTime<<","
         <<books.price<<","<<books.statue<<endl;
        return s;
    }
    Books& operator =(Books &booksdemo){  //重载赋值运算符
        if (this!=&booksdemo){
            bookId = booksdemo.bookId;
            bookName = booksdemo.bookName;
            authorName = booksdemo.authorName;
            categoryNum = booksdemo.categoryNum;
            press = booksdemo.press;
            price = booksdemo.price;
            statue = booksdemo.statue;
        }
        return *this;
    }
};

class User{     //借书人类
private:
    static int allUserNum; //所有用户数量
    int userId;         //  学号，自动生成
    string userName;    //用户姓名
    bool gender;    //性别，（true为男性，false为女性）
    int allBookNum;     //可借书总数
    int haveBookNum;      //已经借书的数量
public:
    User() {
    }

    User(const string &userName, bool gender, int allBookNum, int haveBookNum) :             userName(userName),
                                                                                             gender(gender),
                                                                                             allBookNum(allBookNum),
                                                                                             haveBookNum(haveBookNum) {userId=allUserNum++;}

    int getUserId() const {
        return userId;
    }

    void setUserId(int userId) {
        User::userId = userId;
    }

    const string &getUserName() const {
        return userName;
    }

    void setUserName(const string &userName) {
        User::userName = userName;
    }

    bool isGender() const {
        return gender;
    }

    void setGender(bool gender) {
        User::gender = gender;
    }

    int getAllBookNum() const {
        return allBookNum;
    }

    void setAllBookNum(int allBookNum) {
        User::allBookNum = allBookNum;
    }

    int getHaveBookNum() const {
        return haveBookNum;
    }

    void setHaveBookNum(int haveBookNum) {
        User::haveBookNum = haveBookNum;
    }

public:
    friend ostream & operator<<(ostream& s,User & user){
        s<<user.userId<<","<<user.userName<<","<<user.gender<<","
         <<user.allBookNum<<","<<user.haveBookNum<<endl;
        return s;
    }
};

class BorrowRS{     //borrow relationship,借阅关系类
private:
    int userID; // 借书人ID
    int bookID[20];    //用户可借书籍数量，被借书籍ID数组,10本，11是用来删除的空间
    int already =0;
public:
    int getAlready() const {
        return already;
    }

    void setAlready(int already) {
        BorrowRS::already = already;
    }

private:
    //已经借阅的本数
    string borrowTime[20];  //字符串数组，存放对应每本书的借阅时间
public:
    int getUserId() const {
        return userID;
    }

    void setUserId(int userId) {
        userID = userId;
    }
     int getBookId(int sub)  {   //传入bookId数组的下标，返回该下标对应的数据
        return this->bookID[sub];
    }
    string getBorrowTime(int sub)  {   //传入bookId数组的下标，返回该下标对应的数据
        return this->borrowTime[sub];
    }




    void setBookId(int bookID,int bookIdFlag){
            this->bookID[bookIdFlag] = bookID;
    }
    void setBorrowTime(string borrowTime,int bookIdFlag){
            this->borrowTime[bookIdFlag] = borrowTime;
    }


public:
    BorrowRS(int userID){
        this->userID = userID;
    }
    BorrowRS(){
    }
//    BorrowRS(int userID,int bookID,string borrowTime,int bookIdFlag){ //借书时新建使用，bookIdFlag判断这是借的第几本书
//        this->userID =userID;
//        this->borrowTime[bookIdFlag] = borrowTime;
//        this->borrowTime[bookIdFlag] = bookID;
//    }

    friend ostream & operator <<(ostream & s,BorrowRS & borrowRs){
        s<<"用户ID:"<<borrowRs.userID<<endl;
        for (int i = 0; i < borrowRs.getAlready(); ++i) {
            s<<"书籍ID："<<borrowRs.bookID[i]<<" , 借书时间："<<borrowRs.borrowTime[i]<<endl;
        }
        return s;
    }
};

int Books::allBookNum = 1000;
int User::allUserNum = 1000;

template <typename T>
void readDemo(vector<T> &table,string name){
    T temp;
    string s;
    s = name+".txt";
    fstream file2(s,ios::in);
    int top =-1;

    while(1)
    {
        file2.read((char *)&temp,sizeof(T));
        if(!file2)
            break;
        top++;
        table.push_back(temp);
    }

    file2.close();

//    cout<<"read success!"<<endl;
//    for (int i = 0; i < 2; i++)
//    {
//        cout<<table[i].getid()<<endl;
//    }
}
template <typename T>
void writeDemo(vector<T> table,string name){
    T temp;
    string s;
    s = name+".txt";
    fstream  file1(s,ios::out);
    int length = table.size();
    for (int i = 0; i < length; ++i) {
        file1.write((char *)&table[i],sizeof (T));
    }
    file1.close();
}


string getTime(){
    time_t now = time(0);
    tm *ltm = localtime(&now);
    string  s;
    s = to_string(1900+ltm->tm_year ) + '/'+to_string(1 + ltm->tm_mon) +'/'+ to_string(ltm->tm_mday) +' '
        + to_string(ltm->tm_hour) +":"+ to_string(ltm->tm_min) + ":"+ to_string(ltm->tm_sec);
    return s;
}
void BookManageMenu(){
    cout<<"***********************************************"<<endl;
    cout<<"****************   "<<"图书管理菜单"<<"  ****************"<<endl;
    cout<<"****************   "<<"1.载入信息"<<"   ****************"<<endl;
    cout<<"****************   "<<"2.显示所有"<<"   ****************"<<endl;
    cout<<"****************   "<<"3.增加书籍"<<"   ****************"<<endl;
    cout<<"****************   "<<"4.删除图书"<<"   ****************"<<endl;
    cout<<"****************   "<<"5.修改图书"<<"   ****************"<<endl;
    cout<<"****************   "<<"6.查询图书"<<"   ****************"<<endl;
    cout<<"****************   "<<"7.保存"<<"      ****************"<<endl;
    cout<<"****************   "<<"0.退出"<<"      ****************"<<endl;
    cout<<"***********************************************"<<endl;
    cout<<"***************   "<<"输入操作编号："<<endl;
}
void UserManageMenu(){
    cout<<"***********************************************"<<endl;
    cout<<"****************   "<<"用户管理菜单"<<"         ****************"<<endl;
    cout<<"****************   "<<"1.载入信息"<<"          ****************"<<endl;
    cout<<"****************   "<<"2.注册用户"<<"          ****************"<<endl;
    cout<<"****************   "<<"3.注销"<<"             ****************"<<endl;
    cout<<"****************   "<<"4.修改个人信息"<<"       ****************"<<endl;
    cout<<"****************   "<<"5.查询用户信息"<<"       ****************"<<endl;
    cout<<"****************   "<<"6.保存信息到文件"<<"     ****************"<<endl;
    cout<<"****************   "<<"7.管理员查询all用户"<<"  ****************"<<endl;
    cout<<"****************   "<<"0.退出"<<"             ****************"<<endl;
    cout<<"****************   "<<"********************"<<endl;
    cout<<"****************   "<<"输入操作编号："<<endl;
}
void BorrowRSManageMenu(){
    cout<<"***********************************************"<<endl;
    cout<<"****************   "<<"借还书菜单"<<"    ****************"<<endl;
    cout<<"****************   "<<"1.借书"<<"       ****************"<<endl;
    cout<<"****************   "<<"2.还书"<<"       ****************"<<endl;
    cout<<"****************   "<<"3.查看已借阅"<<"  ****************"<<endl;
    cout<<"****************   "<<"0.退出"<<"       ****************"<<endl;
    cout<<"***********************************************"<<endl;
    cout<<"输入操作编号："<<endl;
}
void MainMenu(){
    cout<<"***********************************************"<<endl;
    cout<<"****************   "<<"主页面"<<"         ****************"<<endl;
    cout<<"****************   "<<"1.图书管理系统"<<"  ****************"<<endl;
    cout<<"****************   "<<"2.用户管理系统"<<"  ****************"<<endl;
    cout<<"****************   "<<"3.借还书"<<"       ****************"<<endl;
    cout<<"***********************************************"<<endl;
    cout<<"输入操作编号："<<endl;
}
void BookManage(vector<Books> &allBooks){
//  定义数据变量存放输入的书籍信息
    string bookName,authorName,press,printTime;
    int categoryNum,bookId;
    double price;
    bool statue;


//    测试数据
    Books demo1("name","zhang",10,"WTU","2021",100,1);
    Books demo2("java","wang",101,"WTU","2021",20,0);
    allBooks.push_back(demo1);
    allBooks.push_back(demo2);

//    显示菜单
    BookManageMenu();
    int choose;
    cin>>choose;
    while (choose!=0){
        switch (choose) {
            case 1:{    //读取文件
                writeDemo(allBooks,"allBooks");
                cout<<"读取成功！"<<endl;
            }
                break;
            case 2:{    //输出全部信息
                cout<<"ID，书籍名称，书籍作者，书籍分类号，出版单位，出版时间，价格，存在状态(0/1)："<<endl;
                for ( int i =0; i<allBooks.size(); ++i) {
                    cout<<allBooks[i];
                }
            }
                break;
            case 3:{//增加

                cout<<"输入添加书籍信息（书籍名称，书籍作者，书籍分类号，出版单位，出版时间，价格，存在状态(0/1)）："<<endl;
                cin>>bookName>>authorName>>categoryNum>>press>>printTime>>price>>statue;
                Books books3(bookName,authorName,categoryNum,press,printTime,price,statue);
                allBooks.push_back(books3);
                cout<<"增加成功！"<<endl;

            }
                break;
            case 4:{//删除
                int flag = 1;
                cout<<"输入要删除书籍的ID编号："<<endl;
                cin>>bookId;
                for ( int i =0; i<allBooks.size(); ++i) {
                    if (bookId==allBooks[i].getBookId()){
                        for (int j = i+1; j <allBooks.size() ; ++j) {
                            allBooks[j-1]= allBooks[j];
                        }
                        allBooks.pop_back();
                        flag = 0;
                        cout<<"删除成功！"<<endl;
                        break;
                    }
                }
                if (flag == 1)
                    cout<<"删除失败！该ID书籍不存在！"<<endl;

            }
                break;
            case 5:{//修改
                int flag  = 0;
                cout<<"输入要修改书籍的ID编号："<<endl;
                cin>>bookId;
                cout<<"输入修改后的信息（书籍名称，书籍作者，书籍分类号，出版单位，出版时间，价格，存在状态(0/1)）："<<endl;

                cin>>bookName>>authorName>>categoryNum>>press>>printTime>>price>>statue;

                for (int i =0; i<allBooks.size(); ++i) {
                    if (bookId==allBooks[i].getBookId()){
                        allBooks[i].setBookName(bookName);
                        allBooks[i].setAuthorName(authorName);
                        allBooks[i].setCategoryNum(categoryNum);
                        allBooks[i].setPress(press);
                        allBooks[i].setPrintTime(printTime);
                        allBooks[i].setPrice(price);
                        allBooks[i].setStatue(statue);
                        flag = 1;
                        cout<<"修改成功！"<<endl;
                        break;
                    }
                }
                if (flag == 0){
                    cout<<"书籍不存在！"<<endl;
                }

            }
                break;
            case 6:{//遍历
                cout<<"输入要修改书籍的ID编号："<<endl;
                cin>>bookId;
                int flag = 0;
                for (int i =0; i<allBooks.size(); ++i) {
                    if (bookId==allBooks[i].getBookId()){
                        cout<<"该书籍信息为："<<endl;
                        cout<<"ID，书籍名称，书籍作者，书籍分类号，出版单位，出版时间，价格，存在状态(0/1)："<<endl;
                        cout<<allBooks[i]<<endl;
                        flag = 1;
                        break;
                    }
                }
                if(flag == 0){
                    cout<<"书籍不存在！"<<endl;
                }
            }
                break;
            case 7:{      //保存
                writeDemo(allBooks,"allBooks");
                cout<<"保存成功！"<<endl;
            }
                break;
            default:
                cout<<"输入错误!"<<endl;
                break;
        }
//继续输出菜单
//        BookManageMenu();
        cout<<endl;
        cout<<"***************   "<<"输入操作编号："<<endl;
        cin>>choose;

    }
}

void UserManage(vector<User> &userTable,vector<BorrowRS> &BorrowRsTable){//用户管理模块
    int userId,allUserNum,allBookNum,haveBookNum;
    string userName;
    bool gender;


    User demo01("li",1,10,0);
    User demo02("wang",0,10,2);
    User demo03("zhang",0,10,5);
    userTable.push_back(demo01);
    userTable.push_back(demo02);
    userTable.push_back(demo03);

    UserManageMenu();
    int choose;
    cin>>choose;
    while (choose!=0){
        switch (choose) {
            case 1:{//读入文件
                writeDemo(userTable,"Alluser");
                cout<<"读取成功！"<<endl;

            }
                break;
            case 2:{//注册
                cout<<"依次输入新增用户的信息：（用户名，性别）"<<endl;
                cin>>userName>>gender;
                User userDemo2(userName,gender,10,0);
                userTable.push_back(userDemo2);
                BorrowRS borrowRsDemo2(userDemo2.getUserId());
                BorrowRsTable.push_back(borrowRsDemo2);
                cout<<"注册成功！"<<endl;
            }
                break;
            case 3:{//注销
                int flag = 1;
                cout<<"输入注销用户的ID"<<endl;
                cin>>userId;
                for (int i = 0; i < userTable.size(); ++i) {
                    if (userId == userTable[i].getUserId()) {
                        for (int j = i + 1; j < userTable.size(); ++j) {
                            userTable[j - 1] = userTable[j];
                        }
                        userTable.pop_back();
                        flag = 0;
                        //删除关系表中的数据
                        int length = BorrowRsTable.size();
                        vector<BorrowRS>::iterator iter;
                        for (iter=BorrowRsTable.begin(); iter != BorrowRsTable.end() ; ++iter) {
                            if (userId == iter->getUserId()){
                                BorrowRsTable.erase(iter);
//                                break;
                            }
                        }
                        cout << "注销成功！" << endl;
                        break;
                    }
                }
                if (flag == 1){
                    cout<<"用户不存在！注销失败！"<<endl;
                }
            }
                break;
            case 4:{//修改
                int flag  = 0;
                cout<<"输入要修改用户的ID："<<endl;
                cin>>userId;
                cout<<"输入修改后的信息："<<endl;
                cin>>userName>>gender;

                for ( int i = 0;i<userTable.size();i++) {
                    if (userId==userTable[i].getUserId()){
                        userTable[i].setUserName(userName);
                        userTable[i].setGender(gender);
                        flag = 1;
                        cout<<"修改成功！"<<endl;
                        break;
                    }
                }
                if (flag == 0){
                    cout<<"用户不存在！"<<endl;
                }

            }
                break;
            case 5:{//查询
                cout<<"输入要查询用户的ID："<<endl;
                cin>>userId;
                int flag = 0;
                for (int i = 0;i<userTable.size();i++) {
                    if (userId==userTable[i].getUserId()){
                        cout<<"该书籍信息为："<<userTable[i]<<endl;
                        flag = 1;
                        break;
                    }
                }
                if(flag == 0){
                    cout<<"用户不存在！"<<endl;
                }
            }
                break;
            case 6:{//保存
//                ofstream ofstream1("user.txt");
//                for (int i= 0;i<userTable.size();i++){
//                    ofstream1<<userTable[i]<<endl;
//                }
//                ofstream1.close();    //输出为可视文件，暂时保存

                writeDemo(userTable,"alluser");
                cout<<"保存成功！"<<endl;
            }
                break;
            case 7:{       //管理员输出所有信息
                for ( int i= 0;i<userTable.size();i++) {
                    cout<<userTable[i];
                }
            }
                break;
            default:{
                cout<<"输入错误!"<<endl;
            }
                break;
        }
//继续输出菜单
//        UserManageMenu();
        cout<<endl;
        cout<<"***************   "<<"输入操作编号："<<endl;
        cin>>choose;
    }
}

bool login(int ID,vector<BorrowRS> &BorrowRsTable){

    bool flag = false ;
    int length = BorrowRsTable.size();
    for (int i = 0;i<length;i++) {
        if (ID==BorrowRsTable[i].getUserId()){
            cout<<"登录成功！"<<endl;
            flag = true;
            break;
        }
    }
    return flag;
}
void logout(vector<BorrowRS> &BorrowRsTable,bool &flag){

//    文件读出
    writeDemo(BorrowRsTable,"allBorrowRS");
    flag = false;
    cout<<"退出成功，信息已保存！"<<endl;
}
void BorrowRSManage(vector<BorrowRS> &BorrowRsTable){
    int userID;
    int bookIDs[10];
    int bookIdFlag=0;
    string borrowTime[10];
    bool loginStatue;

    int choose;

//    文件读入
//    readDemo(BorrowRsTable,"allBorrowRS");
    cout<<"读取成功！"<<endl;

    BorrowRS borrowRs1(1001);
    BorrowRS borrowRs2(1002);
    BorrowRsTable.push_back(borrowRs1);
    BorrowRsTable.push_back(borrowRs2);

//    cout<<BorrowRsTable.size()<<endl;

    cout<<"必须登录，请输入用户ID登录"<<endl;
    cin>>userID;
    bool loginFlag = login(userID,BorrowRsTable);
    if (loginFlag == false)
        cout<<"登录失败！Error,用户不存在"<<endl;
    else{
        BorrowRSManageMenu();
        cin>>choose;
    }
    while (loginFlag){

        switch (choose) {
            case 1:{//                借书
                cout<<"输入借阅书籍本数："<<endl;  //一次借阅多本
                int borrowBookNum;
                cin>>borrowBookNum;

                int alreadyNum=0;
                for (int i = 0; i < BorrowRsTable.size(); ++i) {
                    if(BorrowRsTable[i].getUserId() == userID){
                        alreadyNum = BorrowRsTable[i].getAlready();
                        break;
                    }
                }

                if (alreadyNum ==10 ){
                    cout<<"已满！"<<endl;
                }
                else if ((borrowBookNum+alreadyNum)>10){
                    cout<<"不够！"<<endl;
                }
                else if((borrowBookNum+alreadyNum)<=10){
                    int id;
                    for (int m = 0; m < borrowBookNum; ++m) {
                        cout<<"输入第"<<m+1<<"本书的ID："<<endl;
                        cin>>id;
                        for (int i = 0; i < BorrowRsTable.size(); ++i) {//                在表中查找到该用户表，更新信息
                            if(BorrowRsTable[i].getUserId() == userID){
                                BorrowRsTable[i].setBookId(id,alreadyNum);
                                BorrowRsTable[i].setBorrowTime(getTime(),alreadyNum);
                                BorrowRsTable[i].setAlready(alreadyNum+1);
                                alreadyNum = BorrowRsTable[i].getAlready();
                                cout<<"借书成功！"<<endl;
                                break;
                            }
                        }
                    }
                }

            }
                break;
            case 2:{//                还书
                int alreadyNum;
                int id;
                cout<<"输入归还书籍的ID："<<endl;
                cin>>id;
                for (int i = 0; i < BorrowRsTable.size(); ++i) {//                在表中查找到该用户表，删除文件中用户书籍信息
                    if(BorrowRsTable[i].getUserId() == userID){     //  找到文件中该用户
                        alreadyNum = BorrowRsTable[i].getAlready();     //获取用户已借书籍本数
                        for (int j = 0; j <alreadyNum; j++) {
                            if ((id == BorrowRsTable[i].getBookId(j))){//在对象bookID数组中找到该Id的数据，下标为j
                                for (int k = j; k <=alreadyNum; ++k) {
                                    int lastId = BorrowRsTable[i].getBookId(k+1);
                                    BorrowRsTable[i].setBookId(lastId,k);//将数组j下标后面的数据前移一位,删除书籍ID
                                    string lastTime = BorrowRsTable[i].getBorrowTime(k+1);
                                    BorrowRsTable[i].setBorrowTime(lastTime,k);//将数组j下标后面的时间前移一位，删除借阅时间
                                    BorrowRsTable[i].setAlready(alreadyNum-1);   //更新借阅本数
//                                  扣费
                                    cout<<"还书成功！"<<endl;
                                    break;
                                }
                            }
                        }
                    }
                }
            }
                break;
            case 3:{//                查询已借书籍
                for (int i = 0; i < BorrowRsTable.size(); ++i) {
                    if(BorrowRsTable[i].getUserId() == userID)
                    cout<<BorrowRsTable[i]<<endl;
                }

            }
                break;
            case 0:{
                logout(BorrowRsTable,loginFlag);
            }
                break;
            default:
                cout<<"输入错误！"<<endl;
        }
        if (choose!=0){
//            BorrowRSManageMenu();
            cout<<endl;
            cout<<"***************   "<<"输入操作编号："<<endl;
            cin>>choose;
        }
    }

}


int main() {
    //    vector 集合allBooks存放数据
    vector<Books> allBooks;
    vector<User> userTable;
    vector<BorrowRS> borrowRsTable;//借书关系表，vector存放所有借书对象信息

    int mainChoose;
    MainMenu();
    cin>>mainChoose;
    while (mainChoose){
        switch (mainChoose) {
            case 1:
                BookManage(allBooks);
                break;
            case 2:
                UserManage(userTable,borrowRsTable);
                break;
            case 3:
                BorrowRSManage(borrowRsTable);
                break;

        }
        MainMenu();
        cin>>mainChoose;
    }
    return 0;

}












/*
 * day1:
 * 完成三个基本类的创建
 * 完成图书管理模块
 * 未解决问题：图书删除问题
 *          修改问题
 *          图书信息读入
 *
 *  day2:
 *  解决图书修改问题
 *  完成用户管理模块
 *  完成关系管理模块的登录 和 基本框架
 *
 *  未解决问题：文件读入
 *            vector数据的删除
 *
 *   day3:
 *   解决数据删除问题，
 *   文件读入问题的一半
 *
 *   完成关系管理框架，
 *   完成登录
 *
 *   未解决问题：文件读入，
 *             借书，还书
 *             输出
 *             总框架
 *
 *   day4:
 *          借阅借还书问题，
 *          解决输出问题
 *          完成剩余全部内容
 *
 * */