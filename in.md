# vuex

我是理解为一个全局变量管理器, 里面都是全局变量和全局函数

```javascript
export default {
    namespaced: true,

    // 全局的状态初始化
    state: {
        count: 1,
    },

    // 计算state, 获取对应的值(计算属性?)
    getters: {
        countStatus(state) {
            return state.count >= 1
        }
    },

    // 更新状态的方法, 更新state的唯一方法, commit mutations
    mutations: {
        setCount(state, num) {
            state.count = num
        }
    },

    // 可以异步操作, 可以返回promise
    actions: {
        setCountPromise(context, num) {
            return new Promise((resolve, reject) => {
                if (num > 100) {
                    reject("不能大于一百")
                } else {
                    context.commit('setCount', num)
                    resolve()
                }
            })
        }
    },
}
```

# 调用mutations(用来更新数据的函数集)

一段更新函数调用实例

```javascript
// 第一个参数是函数名, 后面的参数跟第一个参数所对应的函数的参数一致
store.commit('setUserInfo', data.loginData)
```