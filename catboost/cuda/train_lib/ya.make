LIBRARY()




SRCS(
    GLOBAL train.cpp
    GLOBAL query_cross_entropy.cpp
    GLOBAL pointwise.cpp
    GLOBAL querywise.cpp
    GLOBAL pfound_f.cpp
    GLOBAL pair_logit_pairwise.cpp
    GLOBAL multiclass.cpp
)

PEERDIR(
    catboost/cuda/cpu_compatibility_helpers
    catboost/cuda/ctrs
    catboost/cuda/cuda_lib
    catboost/cuda/cuda_util
    catboost/cuda/data
    catboost/cuda/gpu_data
    catboost/cuda/methods
    catboost/cuda/models
    catboost/cuda/targets
    catboost/libs/algo
    catboost/libs/data_new
    catboost/libs/eval_result
    catboost/libs/fstr
    catboost/libs/helpers
    catboost/libs/loggers
    catboost/libs/model
    catboost/libs/options
    catboost/libs/overfitting_detector
    catboost/libs/quantization
    catboost/libs/train_lib
    library/json
    library/object_factory
    library/threading/local_executor
)

INCLUDE(${ARCADIA_ROOT}/catboost/cuda/cuda_lib/default_nvcc_flags.make.inc)

END()
