def damage_calculator(crit_rate,crit_damage):
    crit_rate /= 100
    crit_damage /= 100
    return 1 + crit_rate * crit_damage

crit_rate,crit_damage=map(float, input("输入暴击率和爆伤的百分比: ").split(' '))
print("理论伤害期望为原伤害的%.2f%%" % damage_calculator(crit_rate,crit_damage))