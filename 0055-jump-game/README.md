<h2><a href="https://leetcode.com/problems/jump-game/?source=submission-noac">55. Jump Game</a></h2><h3>Medium</h3><hr><p>You are given an integer array <code>nums</code>. You are initially positioned at the array&#39;s <strong>first index</strong>, and each element in the array represents your maximum jump length at that position.</p>

<p>Return <code>true</code><em> if you can reach the last index, or </em><code>false</code><em> otherwise</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [2,3,1,1,4]
<strong>Output:</strong> true
<strong>Explanation:</strong> Jump 1 step from index 0 to 1, then 3 steps to the last index.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [3,2,1,0,4]
<strong>Output:</strong> false
<strong>Explanation:</strong> You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>4</sup></code></li>
	<li><code>0 &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
</ul>


<p>Return <code>true</code><em> if you can reach the last index, or </em><code>false</code><em> otherwise</em>.</p>



## Wrong Answer ( Time Limited )

시간 생각 안해보고 일단 재귀로 해볼까? 하고 해본 코드

```
bool AgainJump(vector<int>& nums, int index)
{
    if (index >= nums.size() - 1)
        return true;

    for (int i = 1; i <= nums[index]; ++i)
    {
        int idx = index + i;
        if (nums[idx] >= nums.size() - 1)
            return true;

        if (true == AgainJump(nums, idx))
            return true;
    }

    return false;
}

bool canJump(vector<int>& nums) {
    if (1 == nums.size())
        return true;

    return AgainJump(nums, 0);
}
```
