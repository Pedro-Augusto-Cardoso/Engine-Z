class Animation{
    public:
        int frameStart;
        int frameEnd;
        float frameTime;
        inline Animation(int frameStart, int frameEnd, float frameTime){this->frameEnd=frameEnd;this->frameStart=frameStart;this->frameTime=frameTime;};
};