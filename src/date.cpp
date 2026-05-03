#include <ctime>
#include "../include/date.hpp"

Date::Date(const std::string& dateStr) {
        std::istringstream iss(dateStr);
        char delimiter;
        iss >> ev >> delimiter >> ho >> delimiter >> nap;
};

std::string Date::toString() const {
        std::stringstream ss;
        ss << ev << "-" << std::setw(2) << std::setfill('0') << ho << "-" << std::setw(2) << std::setfill('0') << nap;
        return ss.str();
};

bool Date::operator<(const Date& other) const {
        if (ev != other.ev) return ev < other.ev;
        if (ho != other.ho) return ho < other.ho;
        return nap < other.nap;
};

bool Date::operator>(const Date& other) const {
        return other < *this;
};

void Date::setToToday() {
        time_t t = time(nullptr);
        tm* now = localtime(&t);
        ev = now->tm_year + 1900;
        ho = now->tm_mon + 1;
        nap = now->tm_mday;
}