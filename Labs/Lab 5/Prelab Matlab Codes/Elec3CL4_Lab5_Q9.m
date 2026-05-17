%% Elec3CL4_Lab5_Q9
% using "Control System Toolbox"

s = tf('s');

% lab station plant transfer function
G = 311.8 / (s*(s+10.62));

% lab station controller transfer function
kc = 1.87;
z_lead = 13.33;
p_lead = 31.31;
z_lag = 0.1;
p_lag = 0.01;

% transfer functions
G_c_lead = kc * (s+z_lead)/(s+p_lead);
G_c_lag = (s+z_lag)/(s+p_lag);
G_c_lead_lag = G_c_lead * G_c_lag;

% closed loop transfer functions
T_lead = feedback(G_c_lead*G, 1);
T_lead_lag = feedback(G_c_lead_lag*G, 1);

% ramp input
t = 0:0.01:100;
A = 6;
u=A*t;

y_lead = lsim(T_lead, u, t);
y_lead_lag = lsim(T_lead_lag, u, t);

% ramp response plots
figure
plot(t,u,'k', 'LineWidth', 1.5)
hold on
plot(t,y_lead,'r', 'LineWidth', 1.5)
plot(t,y_lead_lag,'b', 'LineWidth', 1.5)
title('Ramp Response')
xlabel('Time (s)')
ylabel('Output \theta(t)')
legend('Input r(t) = 6t', 'Lead Compensator', 'Lag Compensator', 'Location', 'best')
grid on

% kv
disp('Lead Compensator kv:')
kv_lead = dcgain(s*G_c_lead*G)
disp('Lead-Lag Compensator kv:')
kv_lead_lag = dcgain(s*G_c_lead_lag*G)

% ess
disp('Lead Compensator ess:')
ess_lead = A/kv_lead
disp('Lead-Lag Compensator ess:')
ess_lead_lag = A/kv_lead_lag