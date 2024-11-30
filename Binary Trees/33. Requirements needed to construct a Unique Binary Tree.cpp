class Solution
{
    public:
    bool isPossible(int a,int b)
    {
        return (a == 2 || b == 2) && !(a == 2 && b == 2);
    }
};