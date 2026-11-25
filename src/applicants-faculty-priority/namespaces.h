#ifndef NAMESPACES_H
#define NAMESPACES_H

enum class ApplicantsFilterFlags {
    Uninitialized = 0,
    All,
    AdmissionsTrue,
    AdmissionsFalse,
    Error,
};

enum class StudyType {
    Uninitialized = 0,
    NonBudget,
    Budget,
    SpecialRight,
    Kvot,
    CompanySponsor,
    Error,
};

enum class StudyForm {
    Uninitialized = 0,
    Personal,
    PersonalNotPersonal,
    NotPersonal,
    Error,
};

#endif // NAMESPACES_H
