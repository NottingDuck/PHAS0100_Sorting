#include <vector>

template<typename T>
std::vector<T> merge(const std::vector<T> &v1, const std::vector<T> &v2)
{
    std::vector<T> v_merged;
    int i = 0, j = 0;
    while( (i < v1.size()) && (j < v2.size()) )
    {
        if(v1[i] < v2[j])
        {
            v_merged.push_back(v1[i]);
            i++;
        }
        else
        {
            v_merged.push_back(v2[j]);
            j++;
        }
    }
    if(i == v1.size())
    {
        v_merged.insert(v_merged.end(), v2.begin()+j, v2.end());
    }
    else
    {
        for(int k = i; k < v1.size(); k++)
        {
            v_merged.push_back(v1[k]);
        }
    }

    return v_merged;
}

template<typename T>
std::vector<T> rec_merge_sort(const std::vector<T> &v)
{
    if(v.size() == 1)
    {
        return v;
    }
    else
    {
        std::vector<T> v1, v2;
        v1.insert(v1.begin(), v.begin(), v.begin() + v.size()/2);
        v2.insert(v2.begin(), v.begin() + v.size()/2, v.end());
        return merge(rec_merge_sort(v1), rec_merge_sort(v2));
    }
}

template<typename T>
std::vector<T> merge_sort(const std::vector<T> &v)
{
    return rec_merge_sort(v);
}

template<typename T>
std::vector<T> insertion_sort(const std::vector<T> &v)
{
    std::vector<T> v_sorted;
    for(auto val: v)
    {
        if(v_sorted.empty())
        {
            v_sorted.push_back(val);
        }
        else
        {
            typename std::vector<T>::iterator i = v_sorted.begin();
            while(i < v_sorted.end())
            {
                if(val < *i)
                {
                    v_sorted.insert(i, val);
                    break;
                }
                i++;
            }
            if(i == v_sorted.end())
            {
                v_sorted.push_back(val);
            }
        }
    }
    return v_sorted;
}