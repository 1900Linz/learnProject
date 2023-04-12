
#include <iostream>
#include <vector>

class student {
public:
    student(int year, std::string s):mName(s),mId(-1),mAge(year){}

    void setRollNo(int val) { mId = val; }

    int getRollNo() const { return mId; }

    void setName(std::string str) { mName = str; }
    
    std::string getName() const { return mName; }

    int getAge() const { return mAge; };

private:
    int mId;
    
    int mAge;

    std::string mName;

};

class school {
public:
    std::vector<student*> getAllStudent() { return m_StudentList; };

    student getStudent(int rollNo) const { return *m_StudentList[rollNo]; }

    void deleteStudent(int id) {
        if (m_StudentList.empty())
            std::cout << "student datasheet empty! delete error!" << std::endl;
        
        bool delteFlag = 0;
        for (auto i = m_StudentList.begin(); i != m_StudentList.end(); i++)
        {
            if ((*i)->getRollNo() == id)
            {
                m_StudentList.erase(i);
                delteFlag = 1;
                break;
            }
        }

        if (delteFlag) {
            std::cout << "delete finished";
        } else {
            std::cout << "delete error";
        }

        std::cout << std::endl;
    }

    void addStudent(student* person) {
        m_StudentList.push_back(person);
        std::cout << "congratulation! new student";
        std::cout << std::endl;

        updateStudent();
    }

    void updateStudent() {
        std::cout << "updating..." << std::endl;
        std::cout << "current student idList:" << std::endl;

        int _val = 1;
        for (auto i = m_StudentList.begin(); i != m_StudentList.end(); i++)
        {
            (*i)->setRollNo(_val);
            std::cout << "[" << (*i)->getRollNo() << "]  " << (*i)->getName() << "  | now he/she is " << (*i)->getAge() << std::endl;

            _val++;
        }

        std::cout << "...end..." << std::endl;

    }
private:
    std::vector<student*> m_StudentList;
};

int main()
{
    school School;

    student TT(8, "TT");
    student Bob(11, "Bob");

    School.addStudent(&TT);
    std::cout << std::endl;

    School.addStudent(&Bob);
    std::cout << std::endl;

    School.deleteStudent(TT.getRollNo());
    std::cout << std::endl;

    student EE(11, "EE");
    School.addStudent(&EE);
    std::cout << std::endl;

}

