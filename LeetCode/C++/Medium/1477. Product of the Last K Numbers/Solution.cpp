class ProductOfNumbers 
{
    vector<long long> products;

public:
    ProductOfNumbers() 
    {
        products.clear();
        products.push_back(1);
    }
    
    void add(int num) 
    {
        if(num == 0)
        {
            products.clear();
            products.push_back(1);
        }
        else if(products.size() == 0)
        {
            products.push_back(num);
        }
        else
        {
            products.push_back(products.back() * num);
        }
    }
    
    int getProduct(int k) 
    {
        if(k >= products.size())
        {
            return 0;
        }    
        else if(products.size() == k)
        {
            return products.back();
        }
        else
        {
            return products.back() / products[products.size() - 1 - k];
        }

        return -1;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */