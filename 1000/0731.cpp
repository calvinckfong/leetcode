// 731. My Calendar II
class MyCalendarTwo {
public:
    MyCalendarTwo() {}
    
    bool book(int start, int end) {
        // check triple booking
        for (auto [s, e]: overlapBookings) {
            if (max(s, start) < min(e, end)) return false;
        }

        // update overlap booking
        for (auto [s, e]: bookings) {
            if (max(s, start) < min(e, end)) {
                overlapBookings.emplace_back(
                    max(s, start), min(e, end));
            }
        }

        // update booking
        bookings.emplace_back(start, end);
        return true;
    }

private:
    vector<pair<int, int>> bookings;
    vector<pair<int, int>> overlapBookings;
};
