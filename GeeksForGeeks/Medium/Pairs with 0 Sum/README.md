# Pairs with 0 Sum

## Difficulty: Medium

## Platform: GeeksForGeeks

## Problem Link
[View Problem](https://www.geeksforgeeks.org/problems/count-pairs-with-given-sum5022/1)

## Solved On
27 Oct 2026 at 01:17 pm

<h2><a href="https://www.geeksforgeeks.org/problems/count-pairs-with-given-sum5022/1">Pairs with 0 Sum</a></h2><h3>Difficulty Level: Medium</h3><hr><p><span style="font-size: 14pt;">Given an integer array&nbsp;<strong>arr</strong>, return all the&nbsp;unique<strong>&nbsp;</strong>pairs [arr[i], arr[j]] such that&nbsp;i != j and arr[i] + arr[j] == 0.</span></p>
<p><span style="font-size: 14pt;">Note: The pairs must be returned in&nbsp;sorted&nbsp;order, the&nbsp;solution array should also be&nbsp;sorted, and the answer must not contain any&nbsp;duplicate&nbsp;pairs.</span></p>
<p><span style="font-size: 18px;"><strong>Examples:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input: </strong>arr = [-1, 0, 1, 2, -1, -4]
<strong>Output: </strong>[[-1, 1]]<strong>
Explanation: </strong>arr[0] + arr[2] = (-1)+ 1 = 0.
arr[2] + arr[4] = 1 + (-1) = 0.
The distinct pair are [-1,1].</span>
</pre>
<pre><span style="font-size: 18px;"><strong>Input: </strong>arr = [6, 1, 8, 0, 4, -9, -1, -10, -6, -5]
<strong>Output: </strong>[[-6, 6],[-1, 1]]<strong>
Explanation: </strong>The distinct pairs are [-1, 1] and [-6, 6].</span></pre>