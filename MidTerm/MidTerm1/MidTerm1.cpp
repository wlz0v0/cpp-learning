#include <iostream>
#include <string>

class Pager
{
public:
    std::string pagerStr;

    Pager(const std::string& pagerStr_) :
        pagerStr(pagerStr_)
    {}

    Pager(const Pager& rhs) :
        pagerStr(rhs.pagerStr)
    {}
};

class Traveler
{
public:
    std::string travelerStr;

    Traveler(const std::string& travelerStr_) :
        travelerStr(travelerStr_)
    {}

    Traveler(const Traveler& rhs) :
        travelerStr(rhs.travelerStr)
    {}
};

class BusinessTraveler : public Traveler
{
public:
    Pager businessTravelerPager;

    BusinessTraveler() : 
        businessTravelerPager("\0"),
        Traveler("\0")
    {}

    BusinessTraveler(const std::string& businessTravelerPager_,
        const std::string& traveler_) :
        businessTravelerPager(businessTravelerPager_),
        Traveler(traveler_)
    {}

    BusinessTraveler(const BusinessTraveler& rhs) :
        businessTravelerPager(rhs.businessTravelerPager),
        Traveler(rhs.travelerStr)
    {}

    BusinessTraveler& operator=(const BusinessTraveler& rhs)
    {
        businessTravelerPager = rhs.businessTravelerPager;
        travelerStr = rhs.travelerStr;
        return *this;
    }
};

int main()
{
    return 0;
}
