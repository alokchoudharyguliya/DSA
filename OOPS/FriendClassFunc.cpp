class A{
    private:
    int private_var;
    protected:
    int protected_var;
    public:
    A(){
        private_var=10;
        protected_var=20;
    }
    friend class F;
}