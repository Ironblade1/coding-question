class H2O {
public:
    mutex m;
    condition_variable cv;
    int turn;
    H2O() {
        turn = 0;
    }

    void hydrogen(function<void()> releaseHydrogen) {
        unique_lock<mutex> lock(m);
        while(turn==2) cv.wait(lock);
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();
        turn++;
        cv.notify_all();
    }

    void oxygen(function<void()> releaseOxygen) {
        unique_lock<mutex> lock(m);
        while(turn<2) cv.wait(lock);
        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();
        turn = 0;
        cv.notify_all();
    }
};