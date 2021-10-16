#include <iostream>
#include <string>

class Student
{
private:
    std::string* name;
    std::string* id;
public:
    Student() :
        name(new std::string("\0")),
        id(new std::string("\0"))
    {}

    Student(const std::string& name_, const std::string& id_) :
        name(new std::string(name_)),
        id(new std::string(id_))
    {}

    ~Student()
    {
        delete name;
        delete id;
    }

    std::string getName() const
    {
        return *name;
    }

    std::string getID() const 
    {
        return *id;
    }

    void setName(const std::string& name_)
    {
        *name = name_;
    }

    void setID(const std::string& id_)
    {
        *id = id_;
    }

    virtual void getInfo()
    {
        std::cout << getName() << std::endl;
        std::cout << getID() << std::endl;
    }
};

class Graduate : public Student
{
private:
    std::string* supervisor;
public:
    Graduate() : 
        Student(),
        supervisor(new std::string("\0"))
    {}

    Graduate(const std::string& name_, const std::string& id_, const std::string& supervisor_):
        Student(name_, id_),
        supervisor(new std::string(supervisor_))
    {}

    ~Graduate()
    {
        delete supervisor;
    }

    std::string getSupervisor() const
    {
        return *supervisor;
    }

    void setSupervisor(const std::string& supervisor_)
    {
        *supervisor = supervisor_;
    }

    virtual void getInfo()
    {
        std::cout << getName() << std::endl;
        std::cout << getID() << std::endl;
        std::cout << getSupervisor() << std::endl;
    }
};

void print(Student* stu)
{
    stu->getInfo();
}

void print(Student& stu)
{
    stu.getInfo();
}

int main()
{
    Student* stu = new Student("小明", "2020211666");
    Student stu2("uzi", "2020211555");
    Graduate* gra = new Graduate("小虎", "2020211777", "Wh1t3zZ");
    Graduate gra2("faker", "2020211888", "clearlove");
    print(stu);
    print(stu2);
    print(gra);
    print(gra2);
    return 0;
}