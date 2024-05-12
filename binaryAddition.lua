local function toBinary(num)
    local retStr = "";
    while num ~= 0 do
        if num % 2 == 1 then
            retStr = "1" .. retStr 
        else
            retStr = "0" .. retStr
        end
        num = num // 2;
    end
    return retStr
end

local function add_binary(a, b)
    -- Implement me! :D
    return toBinary(a + b)
end
  
return add_binary