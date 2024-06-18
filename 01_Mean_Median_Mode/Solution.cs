using System;
using System.Collections.Generic;
using System.Linq;

public class Solution
{
    private List<int> BubbleSort(List<int> arr)
    {
        int n = arr.Count;
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < n - i - 1; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
        return arr;
    }

    private int SumValue(List<int> ar)
    {
        return ar.Sum();
    }

    public double Mean(List<int> ar)
    {
        return SumValue(ar) / (double)ar.Count;
    }

    public double Median(List<int> ar)
    {
        ar = BubbleSort(ar);
        int n = ar.Count;
        if (n % 2 == 0)
        {
            return (ar[n / 2] + ar[n / 2 - 1]) / 2.0;
        }
        return ar[n / 2];
    }

    public (int, int) Mode(List<int> ar)
    {
        var frequency = new Dictionary<int, int>();
        foreach (var item in ar)
        {
            if (frequency.ContainsKey(item))
                frequency[item]++;
            else
                frequency[item] = 1;
        }

        int maxCount = frequency.Values.Max();
        int mode = frequency.FirstOrDefault(x => x.Value == maxCount).Key;
        return (mode, maxCount);
    }
}
