import pandas as pd
import tensorflow as tf

stock = pd.read_csv('./data/stock_returns_base150.csv')
#stock = pd.read_csv('/Users/shengdongliu/Desktop/data1.csv')
pro=stock.iloc[0:50]
pro['log_lag2_return'] = pro['S1'].shift(2)
pro['log_lag3_return'] = pro['S1'].shift(3)
pro['log_lag4_return'] = pro['S1'].shift(4)
pro['log_lag5_return'] = pro['S1'].shift(5)
pro=pro.iloc[5:50]
pro=pro.iloc[::-1]

pro = pro.drop(pro.columns[[0]], axis=1)
pro['log_return'] = pro['S1'].shift().round(2)
pro = pro.drop(pro.columns[[0]], axis=1)
pro=pro.iloc[1:]

predictors_tf = pro[pro.columns[:13]]
for c in predictors_tf.columns:
     predictors_tf[c] = predictors_tf[c] / max(predictors_tf[c])

temp_classes_tf = pro[pro.columns[13:]].fillna(0)

classes_tf = pd.DataFrame()
for i, x in temp_classes_tf.iterrows():
     classes_tf.set_value(i, str(float(x)), 1)

classes_tf = classes_tf.fillna(0)

training_set_size = int(len(pro) * 0.8)
test_set_size = len(pro) - training_set_size

training_predictors_tf = predictors_tf[:training_set_size]
training_classes_tf = classes_tf[:training_set_size]
test_predictors_tf = predictors_tf[training_set_size:]
test_classes_tf = classes_tf[training_set_size:]

sess = tf.Session()

num_predictors = len(training_predictors_tf.columns)
num_classes = len(training_classes_tf.columns)

feature_data = tf.placeholder("float", [None, num_predictors])
actual_classes = tf.placeholder("float", [None, num_classes])

weights = tf.Variable(tf.truncated_normal([num_predictors, num_classes], stddev=0.0001))
biases = tf.Variable(tf.ones([num_classes]))

model = tf.nn.softmax(tf.matmul(feature_data, weights) + biases)

cost = -tf.reduce_sum(actual_classes*tf.log(model))

training_step = tf.train.AdamOptimizer(learning_rate=0.05).minimize(cost)

init = tf.initialize_all_variables()
sess.run(init)


correct_prediction = tf.equal(tf.argmax(model, 1), tf.argmax(actual_classes, 1))
accuracy = tf.reduce_mean(tf.cast(correct_prediction, "float"))

for i in range(1,45):
  sess.run(
    training_step,
    feed_dict={
      feature_data: training_predictors_tf.values,
      actual_classes: training_classes_tf.values
    }
  )

print ("Test accuracy:" ,sess.run(
      accuracy,
      feed_dict={
        feature_data: test_predictors_tf.values,
        actual_classes: test_classes_tf.values
      }
    ))
