function dfs(n, mem)
    if mem[n] then
        return mem[n]
    end
    if n == 0 then
        return 0        
    elseif n == 1 then
        return 1
    end
    local op1Cost = dfs(n // 2, mem) + 1 + n % 2;
    local op2Cost = dfs(n // 3, mem) + 1 + n % 3;
    local minDay = math.min(op1Cost, op2Cost)
    mem[n] = minDay
    return minDay
end

function min_days(n)
    local mem = {};
    return dfs(n, mem)
end

for i = 1, 10 do
    local days = min_days(i)
    print(days)
end